#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
double arr[10001];

int main(){
    cin>>N;
    double ans=0;
    for(int i=0; i<N; i++){
        double k;
        cin>>arr[i];
        arr[i]=max(arr[i-1]*arr[i],arr[i]);
        ans=max(ans,arr[i]);
    }
    cout<<fixed;
    cout.precision(3);
    cout<<ans;
}
