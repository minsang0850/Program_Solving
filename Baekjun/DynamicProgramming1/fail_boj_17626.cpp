//못 품
#include <iostream>
#include <math.h>

using namespace std;

int n;
int DP[50000];

int dp(int k){
    if(DP[k]!=5)
        return DP[k];
    int root=sqrt(k);
    if(k==root*root){
        DP[k]=1;
        return 1;
    }
    for(int i=1; i<=root; i++){
        DP[k]=min(DP[k],dp(i*i)+dp(k-i*i));
    }
    return DP[k];
}

int main(){
    cin>>n;
    for(int i=0; i<=n; i++)
        DP[i]=5;       
    cout<<dp(n);
    return 0;
}