#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int sum[100000];

int main(){
    cin>>n;
    int answer;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    answer=v[0];
    for(int i=1; i<n; i++){
        if(v[i-1]>0 && v[i]+v[i-1]>0)
            v[i]+=v[i-1];
        if(answer<v[i])
            answer=v[i];
    }
    cout<<answer;
    return 0;
}