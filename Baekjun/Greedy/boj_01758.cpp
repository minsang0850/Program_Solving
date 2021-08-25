#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main(){
    int answer=0;
    cin>>N;
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end(),greater<int>());
    
    for(int i=0; i<N; i++){
        int k=v[i]-i;
        if(k>0)
            answer+=k;
        else
            break;
    }
    cout<<answer;
}