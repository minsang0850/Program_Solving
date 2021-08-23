#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 27

int N;

vector<int> tree[MAX];

void preorder(int k){
    char c='A';
    c+=k;
    cout<<c;
    if(tree[k][0]!=-1)
        preorder(tree[k][0]);
    if(tree[k][1]!=-1)
        preorder(tree[k][1]);
}

void inorder(int k){
    char c='A';
    c+=k;
    if(tree[k][0]!=-1)
        inorder(tree[k][0]);
    cout<<c;
    if(tree[k][1]!=-1)
        inorder(tree[k][1]);
}

void postorder(int k){
    char c='A';
    c+=k;
    if(tree[k][0]!=-1)
        postorder(tree[k][0]);
    if(tree[k][1]!=-1)
        postorder(tree[k][1]);
    cout<<c;
}
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0); 
        
        cin>>N;
        for(int i=0; i<N; i++){
            char a,b,c;
            cin>>a>>b>>c;
            tree[a-'A'].push_back(-1);
            tree[a-'A'].push_back(-1);
            if(b!='.')
                tree[a-'A'][0]=b-'A';
            if(c!='.')
                tree[a-'A'][1]=c-'A';
        }

        preorder(0);
        cout<<endl;
        inorder(0);
        cout<<endl;
        postorder(0);
        return 0;
}