#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int K;
int order[3000];
int tree[3000][2];

int make_tree(int start, int size){
    int mid=(start+start+size-1)/2;
    int left=(start+mid-1)/2;
    int right=(mid+start+size)/2;
    if(size>1){
        tree[order[mid]][0]=order[left];
        tree[order[mid]][1]=order[right];
        make_tree(start,(size-1)/2);
        make_tree(mid+1,(size-1)/2);
    }
    return order[mid];
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0; i<size; i++){
            int k = q.front();
            q.pop();
            if(tree[k][0]!=0){
                q.push(tree[k][0]);
                q.push(tree[k][1]);
            }
            cout<<k;
            if(!q.empty())
                cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>K;
    int size=pow(2,K)-1;
    for(int i=0; i<size; i++){
        cin>>order[i];
        tree[order[i]][0]=0;
        tree[order[i]][1]=0;
    }
    int root = make_tree(0,size);
    bfs(root);
}