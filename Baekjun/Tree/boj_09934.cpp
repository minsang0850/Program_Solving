#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int K;
int order[1025];
int tree[1025][2];

int make_tree(int start, int size){
    int mid=order[(start+size-1)/2];
    int left=order[(start+mid-1)/2];
    int right=order[(mid+1+size-1)/2];
    if(size>1){
        tree[mid][0]=left;
        tree[mid][1]=right;
        make_tree(start,(size-1)/2);
        make_tree(mid+1,(size-1)/2);
    }
    return mid;
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
            cout<<k<<" ";
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