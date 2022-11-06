#include<iostream>
#include<string>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		long n;
		std::string s,ans="";
		std::cin>>n>>s;
		long c=0;
		ans+=std::toupper(s[0]);
		for(long i=1;i<n;i++){
			if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o' || s[i]=='u'){
				if(c){
					ans+=std::to_string(c);
					c=0;
				}
				if(s[i]!=ans[ans.length()-1])
					ans+=s[i];
			}
			else
				c+=1;
		}
		if(c)
			ans+=std::to_string(c);
		std::cout<<ans<<"\n";
	}
	return 0;
}
