#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,K;
    cin>>N>>K;
    queue<int> q;

    for(int i=1; i<=N; i++)
        q.push(i);
    
    cout<<"<";
    while(!q.empty()){
        int tmp;
        for(int i=1; i<K; i++){
            tmp=q.front();
            q.pop();
            q.push(tmp);
        }
        tmp=q.front();
        q.pop();
        cout<<tmp;
        if(!q.empty())
            cout<<", ";
    }
     cout<<">";

     return 0;
}