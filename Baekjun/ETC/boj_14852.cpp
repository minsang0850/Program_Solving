#include <iostream>
#define MOD 1000000007
using namespace std;

long long arr[1000000][2];

int main(){
    int n;
    cin>>n;
    arr[0][0]=0;
    arr[1][0]=2;
    arr[2][0]=7;
    arr[2][1]=1;
    for(int i=3; i<=n; i++){
        arr[i][1]=(arr[i-3][0]+arr[i-1][1])%MOD;
        arr[i][0]=(arr[i][1]*2+arr[i-1][0]*2+arr[i-2][0]*3)%MOD;
    }
    cout<<arr[n][0];
}