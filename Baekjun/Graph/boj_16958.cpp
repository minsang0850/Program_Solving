#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n,t,m;
vector<vector<int>> v;
int graph[1001][1001];
vector<int> answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>t;
    for(int i=0; i<n; i++){
        int s,x,y;
        cin>>s>>x>>y;
        v.push_back({s,x,y});
    }
    for(int i=0; i<n; i++){
        int a = v[i][1];
        int b = v[i][2];
        for(int j=0; j<n; j++){
            int aa = v[j][1];
            int bb = v[j][2];
            graph[i][j]=abs(a-aa)+abs(b-bb);
            if(v[i][0]==1 && v[j][0]==1){
                graph[i][j]=min(graph[i][j],t);
            }
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                    continue;
                if(graph[i][j]>graph[i][k]+graph[k][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        answer.push_back(graph[a-1][b-1]);
    }
    for(int i=0; i<m; i++)    cout<<answer[i]<<"\n";
    return 0;
}