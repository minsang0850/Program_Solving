#include <iostream>
using namespace std;

int map[31][31];
int solve(int n,int m){
	if(map[n][m]!=-1)
		return map[n][m];
	else{
		if(n==m){
			map[n][m]=1;
			return map[n][m];
		}
		map[n][m]=solve(n-1,m-1)+solve(n-1,m);
		return map[n][m];
	}
}

int main() {
	int t,n,m;
	cin>>t;
	for(int i=0; i<31; i++){
		for(int j=0; j<31; j++){
			map[i][j]=-1;
		}
	}
	for(int j=0; j<31; j++){
		map[j][j]=1;
		map[j][0]=1;
	}
	while(t--){
		cin>>n>>m;
		cout<<solve(m,n)<<endl;
	}
	return 0;
}