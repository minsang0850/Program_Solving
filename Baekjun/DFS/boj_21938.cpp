#include <iostream>
#include <vector>

using namespace std;

int n,m,t;
int answer=0;
vector<vector<int>> v;
int visited[1001][1001];

void dfs(int a, int b){
    visited[a][b]=1;
    if(a>0){
        if(v[a-1][b]==1 && visited[a-1][b]==0)
            dfs(a-1,b);
    
    }
    if(a<n-1){
        if(v[a+1][b]==1 && visited[a+1][b]==0)
            dfs(a+1,b);
        
    }
     if(b>0){
        if(v[a][b-1]==1 && visited[a][b-1]==0)
            dfs(a,b-1);
    
    }
    if(b<m-1){
        if(v[a][b+1]==1 && visited[a][b+1]==0)
            dfs(a,b+1);
    }
    
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        vector<int> tmp;
        int r,g,b;
        for(int j=0; j<m; j++){
            cin>>r>>g>>b;
            int k=(r+g+b)/3;
            tmp.push_back(k);
        }
        v.push_back(tmp);
    }
    cin>>t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]>=t)
                v[i][j]=1;
            else
                v[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]==1 && visited[i][j]==0){
                answer++;
                dfs(i,j);
            }    
        }
    }
    cout<<answer<<endl;
}