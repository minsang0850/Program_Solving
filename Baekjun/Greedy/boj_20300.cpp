#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main(){
    int answer;
    cin>>N;
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    answer=v[N-1];
    for(int i=0; i<N/2; i++)
        answer=max(answer,v[i]);
    cout<<answer;
}