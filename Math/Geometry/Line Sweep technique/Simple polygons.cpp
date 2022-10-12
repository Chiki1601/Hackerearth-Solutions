#include <bits/stdc++.h>
using namespace std;
#define DB(x){if(DEBUG)cerr<<__LINE__<<" "<<#x<<" " <<x<<endl;}
int DEBUG = 0, MULTI = 1, GCJ = 0;
struct solver_t;
solver_t *solver;
long long cursor = -1;
static int some_id = 0;
vector<long long>PARENT;
vector<vector<long long>> NEXT;
 
struct pkt_t 
{
    long long X, Y;
    pkt_t operator - (const pkt_t &rhs) const 
    {
        return {X - rhs.X, Y - rhs.Y};
    }
    pkt_t rotate90left() 
    {
        return { -Y, X };
    }
};
 
struct half_line_t 
{
    pkt_t p1, p2;
    long long cur_id, ed_id = 0, id_above = -1, id_below = -1;
    long double coef = 0;
    half_line_t(pkt_t _p1, pkt_t _p2, long long _left_id) : p1(_p1), p2(_p2), cur_id(_left_id) 
    {
        if(p1.X < p2.X) 
            id_above = _left_id;
        else 
        {
            id_below = _left_id;
            swap(this->p1, this->p2);
        }
        ed_id = some_id++;
        coef = (long double)(p2.Y - p1.Y) / (p2.X - p1.X);
    }
    void minus_inf() 
    {
        ed_id = (long long)-1e9;
    }
    void set_parent(long long val) 
    {
        if(id_above == -1) 
            id_above = val;
        if(id_below == -1) 
            id_below = val;
    }
    long long get_minx() 
    {
        return min(p1.X, p2.X);
    }
    long long get_maxx() 
    {
        return max(p1.X, p2.X);
    }
    long double at(long long pos) const 
    {
        long double diff = pos - p1.X;
        return p1.Y + diff * coef;
    }
    bool operator < (const half_line_t &rhs) const 
    {
        long double v1 = at(cursor), v2 = rhs.at(cursor);
        if(v1 != v2) 
            return v1 < v2;
        if(coef != rhs.coef) 
            return coef < rhs.coef;
        return ed_id < rhs.ed_id;
    } 
    long long il_vec(pkt_t pkt) const 
    {
        auto v1 = p2 - p1;
        auto v2 = pkt - p1;
        return v1.X * v2.Y - v1.Y * v2.X;
    }
};
 
struct query_t 
{
    int type;
    long long X = -1, Y = -1, U = -1, node_id = -1;
    void read() 
    {
        cin >> type;
        if(type == 1) 
        {
            cin >> X >> Y;
            X *= 2; 
            Y *= 2;
        } 
        else 
            cin >> U;
    }
};
 
struct st_t 
{
    int SZ = 1;
    vector<int> SUM;
    st_t(int N) 
    {
        while(SZ < N) 
            SZ *= 2;
        SUM.resize(2 * SZ);
    }
    void add(int idx) 
    {
        for(int p = SZ + idx; p >= 1; p /= 2) 
            SUM[p] += 1;
    }
    int get(int idx1, int idx2) 
    {
        int res = 0;
        DB(idx1<<" "<<idx2<<" "<<SZ);
        for(int p1 = SZ + idx1, p2 = SZ + idx2; p1 <= p2; p1 = (p1 + 1) / 2, p2 = (p2 - 1) / 2) 
        {
            if(p1 % 2 == 1) 
                res += SUM[p1];
            if(p2 % 2 == 0) 
                res += SUM[p2];
        }
        return res;
    }
};
 
struct solver_t 
{ 
    int N, go_node_id, Q;
    vector<vector<pkt_t>> POLYS;
    long double field(vector<pkt_t> &POLY) 
    {
        long double res = 0;
        int K = (int)POLY.size();
        for(long long i = 0; i < (long long)K; ++i) 
            res += POLY[i].X * POLY[(i + 1) % K].Y - POLY[(i + 1) % K].X * POLY[i].Y; 
        return res;
    }
    vector<int> GO_NODE_ID, GO_NODE_ID_END;
    void go(int u) 
    {
        GO_NODE_ID[u] = go_node_id++;
        for(int v : NEXT[u]) 
            go(v);
        GO_NODE_ID_END[u] = go_node_id;
    }
    vector<query_t> QUERY; 
    void solve() 
    {
        { 
            cin >> N;
            POLYS.resize(N + 1);
            for(long long n = 1; n <= (long long)N; ++n)
            {
                int K;
                cin >> K;
                auto &POLY = POLYS[n];
                POLY.resize(K);
                for(long long k = 0; k < (long long)K; ++k)
                    cin >> POLY[k].X >> POLY[k].Y;
                for(long long k = 0; k < (long long)K; ++k) 
                {    
                    POLY[k].X *= 2; 
                    POLY[k].Y *= 2;
                }
            }
            cin >> Q;
            QUERY.resize(Q);
            for(long long q = 0; q < (long long)Q; ++q) 
                QUERY[q].read();
        }
        struct state_t 
        {
            vector<half_line_t> ADD;
            vector<set<half_line_t> :: iterator> REM;
            vector<query_t*> QUERIES;
        };
        map<long long, state_t> STATE;
        {
            for(long long q = 0; q < (long long)Q; ++q) 
            {
                if(QUERY[q].type == 1) 
                    STATE[QUERY[q].X].QUERIES.push_back(&QUERY[q]);
            }
        }
        {
            for(long long n = 1; n <= (long long)N; ++n)
                if (field(POLYS[n]) < 0) 
                    reverse((POLYS[n]).begin(), (POLYS[n]).end()); 
            for(long long n = 1; n <= (long long)N; ++n)
            {
                auto &POLY = POLYS[n];
                int K = (int)POLY.size();
                DB(K);
                for(long long k = 0; k < (long long)K; ++k)  
                {
                    auto p1 = POLY[k];
                    auto p2 = POLY[(k + 1) % K];
                    if(p1.X == p2.X) 
                        continue;
                    DB(p1.X<<" "<<p1.Y<<" "<<p2.X<<" "<<p2.Y);
                    auto v1 = p2 - p1;
                    auto v2 = v1.rotate90left();
                    DB(v2.X<<" "<<v2.Y);
                    auto hl = half_line_t(p1, p2, n);
                    STATE[hl.get_minx()].ADD.push_back(hl);
                }
            }
        }
        set<half_line_t> XX;
        PARENT.clear();
        NEXT.clear();
        PARENT.resize(N + 1, -1);
        NEXT.resize(N + 1);
        PARENT[0] = 0;
        auto BOTTOM = half_line_t({0, -1}, {(long long)1e9, -1}, 0);
        BOTTOM.set_parent(PARENT[0]);
        for(long long g = 0; g < (long long)5; ++g)
        {
            auto TOP = half_line_t({(long long) 0, (long long) 1e9 + g}, {(long long) 1e9, (long long) 1e9 + g}, 0);
            TOP.set_parent(PARENT[0]);
            XX.insert(TOP);
        }
        XX.insert(BOTTOM);
        {
            for(auto elXXX : STATE) 
            {
                DB(XX.size());
                long long x = elXXX.first;
                state_t & state = elXXX.second;
                cursor = x;
                for(auto que : state.QUERIES) 
                {
                    pkt_t pkt = {que->X, que->Y};
                    auto HE = half_line_t(pkt, {pkt.X + 1, pkt. Y}, -2);
                    HE.minus_inf();
                    auto el = XX.lower_bound(HE);
                    long long tree_id;
                    for(long long g = 0; g < (long long)3; ++g)
                        el++;
                    long long il_vec = el->il_vec(pkt);
                    DB(il_vec<<" "<<el->at(x)<<" "<<HE.at(x)<<" "<<el->id_below<<" "<<el->id_above);
                    while(il_vec < 0) 
                    {
                        el--;
                        il_vec = el->il_vec(pkt);
                    }
                    if(il_vec > 0) 
                        tree_id = el->id_above;
                    else if(il_vec == 0) 
                        tree_id = el->cur_id;
                    else 
                        tree_id = el->id_below;
                    DB(pkt.X<<" "<<pkt.Y<<" "<<tree_id);
                    que->node_id = tree_id;
                }
                cursor = x - 1;
                for(auto rem : state.REM) 
                    XX.erase(rem);
                cursor = x + 1;
                for(auto add : state.ADD) 
                {
                    long long cur_id = add.cur_id;
                    if(PARENT[cur_id] == -1) 
                    {
                        auto cand = XX.lower_bound(add);
                        DB("TODO"<<" "<<cur_id<<" "<<cand->id_below);
                        PARENT[cur_id] = cand->id_below;
                        NEXT[PARENT[cur_id]].push_back(cur_id);
                    }
                    add.set_parent(PARENT[cur_id]);
                    auto res = XX.insert(add);
                    assert(res.second);
                    STATE[add.get_maxx()].REM.push_back(res.first);
                }
                cursor = x;
                for (auto que : state.QUERIES) 
                {
                    pkt_t pkt = {que->X, que->Y};
                    auto HE = half_line_t(pkt, {pkt.X + 1, pkt. Y}, -2);
                    HE.minus_inf();
                    auto el = XX.lower_bound(HE);
                    long long tree_id;   
                    for(long long g = 0; g < (long long)3; ++g)
                        el++;
                    long long il_vec = el->il_vec(pkt);
                    DB(il_vec<<" "<<el->at(x)<<" "<<HE.at(x)<<" "<<el->id_below<<" "<<el->id_above);
                    while(il_vec < 0) 
                    {
                        el--;
                        il_vec = el->il_vec(pkt);
                    }
                    if(il_vec > 0)  
                        tree_id = el->id_above;
                    else if(il_vec == 0) 
                        tree_id = el->cur_id;
                    else 
                        tree_id = el->id_below;
                    DB(pkt.X<<" "<<pkt.Y<<" "<<tree_id);
                    if(que->node_id == tree_id) 
                        que->node_id = tree_id;
                    else 
                    {
                        if(PARENT[que->node_id] == tree_id) {} 
                        else if(que->node_id == PARENT[tree_id]) 
                            que->node_id = tree_id;
                        else 
                            assert(0);
                    }
                }
            }
        }
        go_node_id = 0;
        GO_NODE_ID.clear(); 
        GO_NODE_ID.resize(N + 1);
        GO_NODE_ID_END.clear(); 
        GO_NODE_ID_END.resize(N + 1);
        go(0);
        DB(XX.size());
        {
            st_t st(N + 1);
            vector<long long> CNT(N + 1);
            for(long long q = 0; q < (long long)Q; ++q)
            {
                if(QUERY[q].type == 1) 
                    st.add(GO_NODE_ID[QUERY[q].node_id]);
                else 
                    cout << st.get(GO_NODE_ID[QUERY[q].U],  GO_NODE_ID_END[QUERY[q].U] - 1) << "\n";
            }
        }
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    if(MULTI || GCJ)
        cin >> t;
    else 
        t = 1;
    for(long long i = 1; i <= (long long)t; ++i)
    {
        solver = new solver_t();
        solver->solve();
        if(t == INT_MAX) 
        {
            while(cin.peek() <= ' ') 
            { 
                char x; 
                if(!cin.get(x)) 
                    break; 
            }
            if(cin.eof()) 
                break;
        }
    }
    return 0;
}
