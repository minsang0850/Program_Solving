#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> A,B,C;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        A.push_back(k);
    }
    for(int i=0; i<M; i++){
        int k;
        cin>>k;
        B.push_back(k);
    }
    int ai=0; int bi=0;
    int asize=A.size();
    int bsize=B.size();
    for(int i=0; i<N+M; i++){
        if(ai<asize && bi<bsize){
            if(A[ai]<=B[bi]){
                cout<<A[ai++]<<" ";
            }
            else
                cout<<B[bi++]<<" ";
        }
        else if(ai==asize){
            cout<<B[bi++]<<" ";
        }
        else
            cout<<A[ai++]<<" ";
    }
    return 0;
}