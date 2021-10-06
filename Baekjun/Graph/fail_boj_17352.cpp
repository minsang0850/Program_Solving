#include <iostream>
#include <vector>

using namespace std;

int n;
int visited[300001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++)
        visited[i]=i;
    for(int i=0; i<n-2; i++){
        int a,b;
        cin>>a>>b;
        int k;
        if(a<b)
            k=visited[a];
        else
            k=visited[b];
        visited[a]=k;
        visited[b]=k;   
    }
    int a=visited[1];
    int b=0;
    for(int i=2; i<=n; i++){
        if(visited[i]!=a){
            if(visited[i]==i){
                b=i;
                break;
            }
            visited[i]=visited[visited[i]];
        }
    }
    //for(int i=1; i<=n; i++) cout<<visited[i]<<" ";
    cout<<a<<" "<<b;
}