#include <iostream>

using namespace std;

int bridge[31][31];

int N,M,T;

int DP(int n, int m){
    if(bridge[n][m]!=0)
        return bridge[n][m];
    if(n==m){
        bridge[n][m]=1;
        return 1;
    }
    if(n==1){
        for(int j=1; j<=M; j++)
            bridge[1][j]=j;
        return bridge[n][m];
    }
    int answer=0;
    for(int i=n-1; i<m; i++){
        answer+=DP(n-1,i);
    }
    bridge[n][m]=answer;
    return answer;
}

int main(){
    cin>>T;
    while(T--){
        cin>>N>>M;
        int k=DP(N,M);
        cout<<k<<endl;
    }    
    return 0;
}