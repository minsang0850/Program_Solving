#include <iostream>
#define MOD 1000000007

using namespace std;

int n;
int DP[2000][2000];

int ncr(int n, int r){
    if(DP[n][r]!=0)
        return DP[n][r];
    if(r==0){
        DP[n][r]=1;
        return 1;
    }
    if(r==1){
        DP[n][r]=n;
        return n;
    }
    if(n==r)
        return 1;
    DP[n][r]=(ncr(n-1,r-1)+ncr(n-1,r))%MOD;
    return DP[n][r];
}

int main(){
    int answer=0;
    cin>>n;
    for(int a=1; a<=n; a++){
        int b=n-a;
        if((a*5+b)%3==0){
            answer+=ncr(n-1,a-1);
            answer%=MOD;
        }
    }
    cout<<answer;
}