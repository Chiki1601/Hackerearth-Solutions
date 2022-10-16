#include <bits/stdc++.h>
using namespace std;
 
template<typename T, typename U> static void amax(T &x, U y) 
{ 
	if(x < y) 
		x = y; 
}
 
class SuffixArray 
{
public:
	typedef char Alpha;
	typedef int Index;
	void build(const Alpha *str, Index n, int AlphaSize);
	void build(const Alpha *str, Index n);
	inline Index length() const { return static_cast<Index>(suffixArray.size() - 1);}
	vector<Index> suffixArray;
	template<typename AlphaT> void sa_is(const AlphaT *str, Index n, int AlphaSize, Index *sa, vector<Index> &bucketOffsets);
	template<typename AlphaT> void inducedSort(const AlphaT *str, Index n, int AlphaSize, const vector<bool> &types, Index *sa, vector<Index> &bucketOffsets);
	template<typename AlphaT> void countAlphabets(const AlphaT *str, Index n, int AlphaSize, vector<Index> &bucketOffsets, bool b = false);
	template<typename AlphaT> void getBucketOffsets(const AlphaT *str, Index n, bool dir, int AlphaSize, vector<Index> &bucketOffsets);
	void buildInverseSuffixArray();
	void computeLCPArray(const Alpha *str);
	vector<Index> inverseSuffixArray, lcpArray;
};
 
void SuffixArray::build(const Alpha *str, Index n, int AlphaSize) 
{
	suffixArray.resize(n + 1);
	if(n == 0) 
		suffixArray[0] = 0;
	else 
	{
		vector<Index> bucketOffsets(max(AlphaSize, (n + 1) / 2) + 1);
		sa_is<Alpha>(str, n, AlphaSize, &suffixArray[0], bucketOffsets);
	}
}
 
void SuffixArray::build(const Alpha *str, Index n) 
{
	Alpha maxElem = *std::max_element(str, str + n);
	assert(maxElem + 0 < numeric_limits<int>::max());
	build(str, n, (int)(maxElem + 1));
}
 
template<typename AlphaT>
void SuffixArray::sa_is(const AlphaT *str, Index n, int AlphaSize, Index *sa, vector<Index> &bucketOffsets) 
{
	vector<bool> types(n + 1);
	types[n - 1] = 0; types[n] = 1;
	for(Index i = n - 2; i >= 0; i --)
		types[i] = str[i] < str[i + 1] || (str[i] == str[i + 1] && types[i + 1]);
	countAlphabets(str, n, AlphaSize, bucketOffsets);
	getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	fill(sa, sa + n + 1, -1);
	for(Index i = 1; i < n; i ++)
		if(types[i] && !types[i - 1]) 
			sa[-- bucketOffsets[(int)str[i]]] = i;
	sa[0] = n;
	inducedSort(str, n, AlphaSize, types, sa, bucketOffsets);
	Index n1 = 0;
	for(Index i = 0; i <= n; i++) 
	{
		Index j = sa[i];
		if(j > 0 && types[j] && !types[j - 1]) 
			sa[n1 ++] = j;
	}
	Index *buffer = sa + n1;
	fill(buffer, sa + n + 1, -1);
	Index uniqueLMSCount = 0, prevPos = -1;
	assert(sa[0] == n);
	buffer[sa[0] / 2] = uniqueLMSCount ++;	
	for(Index i = 1; i < n1; i ++) 
	{
		Index pos = sa[i]; 
		bool diff = false;
		if(prevPos == -1) 
			diff = true;
		else for(Index j = pos, k = prevPos; ; j++, k++) 
		{
			if(str[j] != str[k] || types[j] != types[k]) 
			{
				diff = true;
				break;
			} 
			else if(j != pos && ((types[j] && !types[j - 1]) || (types[k] && !types[k - 1])))
				break;
		}
		if(diff) 
		{
			uniqueLMSCount++;
			prevPos = pos;
		}
		buffer[pos / 2] = uniqueLMSCount - 1;
	}
	for(Index i = n, j = n; i >= n1; i--)
		if(sa[i] >= 0) 
			sa[j --] = sa[i];
	Index *sa1 = sa, *s1 = sa + n + 1 - n1;
	if(uniqueLMSCount == n1)
		for(Index i = 0; i < n1; i++) 
			sa1[s1[i]] = i;
	else
		sa_is<Index>(s1, n1 - 1, uniqueLMSCount, sa1, bucketOffsets);
	countAlphabets(str, n, AlphaSize, bucketOffsets);
	getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	for(Index i = 1, j = 0; i <= n; i++)
		if(types[i] && !types[i - 1]) 
			s1[j ++] = i;
	for(Index i = 0; i < n1; i++) 
		sa1[i] = s1[sa1[i]];
	fill(sa + n1, sa + n + 1, -1);
	for(Index i = n1 - 1; i >= 1; i--) 
	{
		Index j = sa[i]; sa[i] = -1;
		sa[--bucketOffsets[(int)str[j]]] = j;
	}
	inducedSort(str, n, AlphaSize, types, sa, bucketOffsets);
}
 
template<typename AlphaT>
void SuffixArray::inducedSort(const AlphaT *str, Index n, int AlphaSize, const vector<bool> &types, Index *sa, vector<Index> &bucketOffsets) 
{
	getBucketOffsets(str, n, false, AlphaSize, bucketOffsets);
	for(Index i = 0; i < n; i++) 
	{
		Index j = sa[i] - 1;
		if(j >= 0 && !types[j]) 
			sa[bucketOffsets[(int)str[j]]++] = j;
	}
	getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	for(Index i = n; i >= 1; i--) 
	{
		Index j = sa[i] - 1;
		if(j >= 0 && types[j]) 
			sa[--bucketOffsets[(int)str[j]]] = j;
	}
}
 
template<typename AlphaT>
void SuffixArray::countAlphabets(const AlphaT *str, Index n, int AlphaSize, vector<Index> &bucketOffsets, bool b) 
{
	if(b || (int)bucketOffsets.size() / 2 >= AlphaSize) 
	{
		vector<Index>::iterator alphabetCounts = b ? bucketOffsets.begin() : bucketOffsets.begin() + AlphaSize;
		fill(alphabetCounts, alphabetCounts + AlphaSize, 0);
		for(Index i = 0; i < n; i ++)
			alphabetCounts[(int)str[i]] ++;
	}
}
 
template<typename AlphaT>
void SuffixArray::getBucketOffsets(const AlphaT *str, Index n, bool dir, int AlphaSize, vector<Index> &bucketOffsets) 
{
	vector<Index>::iterator alphabetCounts;
	if((int)bucketOffsets.size() / 2 < AlphaSize) 
	{
		countAlphabets(str, n, AlphaSize, bucketOffsets, true);
		alphabetCounts = bucketOffsets.begin();
	} 
	else 
		alphabetCounts = bucketOffsets.begin() + AlphaSize;
	Index cumsum = 1;	
	if(dir) 
	{
		for(int i = 0; i < AlphaSize; i++) 
		{
			cumsum += alphabetCounts[i];
			bucketOffsets[i] = cumsum;
		}
	} 
	else 
	{
		for(int i = 0; i < AlphaSize; i++) 
		{
			Index x = alphabetCounts[i];
			bucketOffsets[i] = cumsum;
			cumsum += x;
		}
	}
}
 
void SuffixArray::buildInverseSuffixArray() 
{
	Index n = length();
	inverseSuffixArray.resize(n + 1);
	for(Index i = 0; i <= n; i ++)
		inverseSuffixArray[suffixArray[i]] = i;
}
 
void SuffixArray::computeLCPArray(const Alpha *str) 
{
	int n = length();
	lcpArray.resize(n + 2);
	Index h = 0;
	for(Index i = 0; i < n; i ++) 
	{
		Index pos = inverseSuffixArray[i];
		Index j = suffixArray[pos - 1];
		Index hbound = min(n - j, n - i);
		for(Index k = 0; h < hbound && str[i + h] == str[j + h]; ++h);
		lcpArray[pos - 1] = h;
		if(h > 0) 
			--h;
	}
	lcpArray[n] = lcpArray[n + 1] = 0;
}
 
struct SuffixTree 
{
	typedef SuffixArray::Alpha Alpha;
	typedef SuffixArray::Index Index;
	struct Node 
	{
		Index begin, end, parent;
		Node() {}
		Node(Index begin_, Index end_, Index parent_) : begin(begin_), end(end_), parent(parent_) {}
		Index length() const { return end - begin; }
	};
	enum { TERMINATOR = '\1' };
	SuffixArray sa;	
	vector<Alpha> alphas;
	vector<Index> stringIndex, stringPos, leafs, edges, offsets, order, lefts, rights, depths;		
	vector<Node> nodes;				
	Index size() const { return static_cast<Index>(alphas.size()); }
	Index numNodes() const { return static_cast<Index>(nodes.size()); }
	void build(const Alpha *str, Index n, Index nStrings = 1) 
	{
		assert(str != NULL);
		assert(n > 0 && str[n - 1] == TERMINATOR);
		assert(nStrings >= 1);
		assert(TERMINATOR != '\0' && count(str, str + n, '\0') == 0);
		assert(count(str, str + n, TERMINATOR) == nStrings);
		sa.build(str, n);
		sa.buildInverseSuffixArray();
		sa.computeLCPArray(str);
		stringIndex.resize(n);
		stringPos.resize(nStrings + 1);
		for(Index pos = 0, k = 0; pos < n; ++ pos) 
		{
			stringIndex[pos] = k;
			if(str[pos] == TERMINATOR)
				stringPos[++ k] = pos + 1;
		}
		for(Index i = 1; i < n; ++ i) 
		{
			Index posx = sa.suffixArray[i], posy = sa.suffixArray[i + 1];
			Index ix = stringIndex[posx], iy = stringIndex[posy];
			Index dist = min(stringPos[ix + 1] - 1 - posx, stringPos[iy + 1] - 1 - posy);
			sa.lcpArray[i] = min(sa.lcpArray[i], dist);
		}
		buildSuffixTree(str, n, &sa.suffixArray[0] + 1, &sa.lcpArray[0] + 1);
	}
	void buildAll(const Alpha *str, Index n, Index nStrings = 1) 
	{
		build(str, n, nStrings);
		buildGraph();
		depthFirstTraversal();
	}
private:
	void buildSuffixTree(const Alpha *str, Index n, const Index *suffixArray, const Index *lcpArray) 
	{
		assert(n > 0 && str[n - 1] == TERMINATOR);
		nodes.resize(n * 2);
		alphas.assign(str, str + n);
		leafs.assign(n, -1);
		Index pNodes = 0;
		Node *curNode = new(&nodes[pNodes ++]) Node(0, 0, -1);
		Index curDepth = 0;
		for(Index i = 0; i < n; ++ i) 
		{
			Index pos = suffixArray[i];
			Index lcp = i == 0 ? 0 : lcpArray[i - 1];
			while(curDepth != lcp) 
			{
				Index len = curNode->length();
				if(curDepth - len < lcp) 
				{
					Index midPos = curNode->end - (curDepth - lcp);
					Node *newNode = new(&nodes[pNodes ++]) Node(curNode->begin, midPos, curNode->parent);
					curNode->begin = midPos;
					curNode->parent = static_cast<Index>(newNode - &nodes[0]);
					curDepth -= curNode->length();
					curNode = newNode;
					break;
				}
				curNode = &nodes[curNode->parent];
				curDepth -= len;
			}
			Index leafEndPos = stringPos[stringIndex[pos] + 1];
			Node *newLeaf = new(&nodes[pNodes ++]) Node(pos + lcp, leafEndPos, static_cast<Index>(curNode - &nodes[0]));
			curNode = newLeaf;
			curDepth += newLeaf->length();
			leafs[pos] = static_cast<Index>(newLeaf - &nodes[0]);
		}
		nodes.resize(pNodes);
		for(Index i = 1; i < n; ++ i)
			assert(comparePos(suffixArray[i - 1], suffixArray[i]) <= 0);
	}
public:
	bool isLeaf(Index i) const 
	{
		return i != 0 && alphas[nodes[i].end - 1] == TERMINATOR;
	}
	int comparePos(Index i, Index j) const 
	{
		Alpha a = alphas[i], b = alphas[j];
		if(a != TERMINATOR || b != TERMINATOR)
			return a > b ? 1 : a < b ? -1 : 0;
		else 
		{
			Index x = leafs[i], y = leafs[j];
			return x > y ? 1 : x < y ? -1 : 0;
		}
	}
	void buildGraph() 
	{
		Index nNodes = numNodes();
		assert(nNodes > 0);
		edges.resize(nNodes);
		offsets.assign(nNodes + 1, 0);
		for(Index i = 1; i < nNodes; ++i)
			++offsets[nodes[i].parent];
		for(Index i = 0; i < nNodes; ++i)
			offsets[i + 1] += offsets[i];
		for(Index i = nNodes - 1; i > 0; --i)
			edges[--offsets[nodes[i].parent]] = i;
	}
	const Index *edgesBegin(Index i) const { return &edges[0] + offsets[i]; }
	const Index *edgesEnd(Index i) const { return &edges[0] + offsets[i + 1]; }
	void depthFirstTraversal() 
	{
		assert(offsets.size() > 0);
		Index nNodes = numNodes();
		order.clear(); 
		order.reserve(nNodes);
		lefts.assign(nNodes, -1);
		rights.assign(nNodes, -1);
		depths.resize(nNodes);
		depths[0] = 0;
		Index curLeafs = 0;
		vector<Index> stk;
		stk.push_back(0);
		while(!stk.empty()) 
		{
			Index i = stk.back(); 
			stk.pop_back();
			if(lefts[i] != -1) 
			{
				rights[i] = curLeafs;
				continue;
			}
			order.push_back(i);
			lefts[i] = curLeafs;
			stk.push_back(i);
			const Index *p = edgesBegin(i), *q = edgesEnd(i);
			if(p == q) 
				++curLeafs;
			else 
			{
				do 
				{
					Index child = *(-- q);
					depths[child] = depths[i] + nodes[child].length();
					stk.push_back(child);
				} while(p != q);
			}
		}
	}
 
public:
	void debugOutputGraphviz(bool visSuffixLink = false) const 
	{
		ostream &o = std::cerr;
		o << "digraph {\n";
		o << "style = dot;\n";
		Index nNodes = numNodes();
		for(Index i = 0; i < nNodes; ++ i) 
		{
			const Node &node = nodes[i];
			if(node.parent == -1) 
				continue;
			o << node.parent << " -> " << i << " [label=<";
			for(Index p = node.begin; p != node.end; ++ p) 
			{
				Alpha a = alphas[p];
				if(a == TERMINATOR)
					o << '$';
				else
					o << a;
			}
			o << ">];\n";
		}
		o << "}" << endl;
	}
 
	string debugGetPathString(Index i) const 
	{
		string res;
		for(Index j = i; j != -1; ) 
		{
			const Node &node = nodes[j];
			for(Index p = node.end - 1; p >= node.begin; -- p)
				res += alphas[p];
			j = node.parent;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
 
int main() 
{
	int n;
	while(~scanf("%d", &n)) 
	{
		unique_ptr<char[]> S(new char[n + 2]);
		cin >> S.get();
		S[n] = SuffixTree::TERMINATOR;
		S[n + 1] = 0;
		SuffixTree st;
		st.buildAll(S.get(), n + 1);
		int K = 0, Q;
		while(1 << K < n + 1) 
			++K;
		int numNodes = st.numNodes();
		vector<long long> nodeValue(numNodes);
		for(int i = 0; i < numNodes; ++i)
			nodeValue[i] = (long long)(st.rights[i] - st.lefts[i]) * st.depths[i];
		vector<vector<int>> powPar(K, vector<int>(numNodes));
		vector<vector<long long>> powParMax(K, vector<long long>(numNodes));
		for(int i = 0; i < numNodes; ++i)
		{
			powPar[0][i] = i == 0 ? 0 : st.nodes[i].parent;
			powParMax[0][i] = nodeValue[i];
		}
		for(int k = 1; k < K; ++k)
			for(int i = 0; i < numNodes; ++i)
		{
			int p = powPar[k - 1][i];
			powPar[k][i] = powPar[k - 1][p];
			powParMax[k][i] = max(powParMax[k - 1][i], powParMax[k - 1][p]);
		}
		auto levelAncestor = [K, &st, &powPar](int i, int d) -> pair<int, int> 
		{
			for(int k = K - 1; k >= 0; -- k) 
			{
				int p = powPar[k][i];
				if(d <= st.depths[p])
					i = p;
			}
			return make_pair(i, st.nodes[i].length() - (st.depths[i] - d));
		};
		cin >> Q;
		for(int ii = 0; ii < Q; ++ii)
		{
			int v, l, r, nodeL, offsetL, nodeR, offsetR;
			cin >> v >> l >> r; 
			--v;
			tie(nodeL, offsetL) = levelAncestor(st.leafs[v], l);
			tie(nodeR, offsetR) = levelAncestor(st.leafs[v], r);
			long long ans = 0;
			amax(ans, (long long)(st.rights[nodeR] - st.lefts[nodeR]) * r);
			if(nodeL != nodeR) 
			{
				int i = st.nodes[nodeR].parent;
				for(int k = K - 1; k >= 0; -- k) 
				{
					int p = powPar[k][i];
					if(st.depths[nodeL] <= st.depths[p]) 
					{
						amax(ans, powParMax[k][i]);
						i = p;
					}
				}
				assert(i == nodeL);
				amax(ans, nodeValue[nodeL]);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
