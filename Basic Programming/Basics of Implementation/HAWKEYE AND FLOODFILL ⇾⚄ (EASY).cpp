#include<iostream>
#include<vector>
#include<cmath>
int main(){
	int N;
	std::cin>>N;
	std::vector<std::vector<int>> arr;
	arr.resize(N, std::vector<int>(N, 0));
	long p,r,c;
	std::cin>>r>>c>>p;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(std::max(std::abs(r-i),std::abs(c-j))<=p)
				arr[i][j]=p-std::max(std::abs(r-i),std::abs(c-j));
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
