#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000 + 1;

int N;
bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void find_parent(int k){
    for(int i=0; i<tree[k].size(); i++){
        if(visited[tree[k][i]]==false){
            visited[tree[k][i]]=true;
            parent[tree[k][i]]=k;
            find_parent(tree[k][i]);
        }
    }
}

int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0); 

        for(int i=1; i<=N; i++)
            visited[i]=false;
        cin>>N;
        for(int i=0; i<N-1; i++){
            int a,b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        find_parent(1);

        for(int i=2; i<=N; i++)
            cout<<parent[i]<<"\n";
        
        return 0;
}