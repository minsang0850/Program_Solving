#include <iostream>
using namespace std;

int t,n;
int arr[2][100000];
int cache[2][100000];
int solve(int a,int b){
	if(cache[a][b]!=-1)
		return cache[a][b];
	if(b==n-1)
		return cache[a][b]=arr[a][b];
	if(b==n-2)
		return cache[a][b]=arr[a][b]+arr[1-a][b+1];
	cache[a][b]=max(arr[a][b]+solve(1-a,b+1) , arr[a][b]+solve(1-a,b+2));
	return cache[a][b];
}

int main() {
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin>>arr[i][j];
			}
		}
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cache[i][j]=-1;
			}
		}
		cout<<max(solve(0,0),solve(1,0))<<endl;
	}
	return 0;
}