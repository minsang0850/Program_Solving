#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> v;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    int k;
    cin>>k;
    v.push_back(k);
    for(int i=1; i<N; i++){
        cin>>k;
        v.push_back(v[i-1]+k);
    }  
    while(M--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a!=0){
            cout<<v[b]-v[a-1]<<"\n";
        }
        else{
            cout<<v[b]<<"\n";
        }
    }
}