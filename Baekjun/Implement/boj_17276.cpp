#include <iostream>
#include <vector>

using namespace std;

int n,d;
vector<vector<int>> v;

void rollin(){
    vector<vector<int>> ret=v;
    for(int i=0; i<n; i++){
        ret[i][n/2]=v[i][i];
    }
    for(int i=0; i<n; i++){
        ret[i][n-1-i]=v[i][n/2];
    }
    for(int i=0; i<n; i++){
        ret[n/2][n-i-1]=v[i][n-i-1];
    }
    for(int i=0; i<n; i++){
        ret[i][i]=v[n/2][i];
    }
    v=ret;

}

void rollin2(){
    vector<vector<int>> ret=v;
    for(int i=0; i<n; i++){
        ret[n/2][i]=v[i][i];
    }
    for(int i=0; i<n; i++){
        ret[i][i]=v[i][n/2];
    }
    for(int i=0; i<n; i++){
        ret[i][n/2]=v[i][n-i-1];
    }
    for(int i=0; i<n; i++){
        ret[n-1-i][i]=v[n/2][i];
    }
v=ret;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>d;
        v.clear();
        for(int i=0; i<n; i++){
            vector<int> tmp;
            for(int j=0; j<n; j++){
                int k;
                cin>>k;
                tmp.push_back(k);
            }
            v.push_back(tmp);
        }
        if(d>0){
            d/=45;
            for(int i=0; i<d; i++)
                rollin();
        }
        else{
            d*=-1;
            d/=45;
            for(int i=0; i<d; i++)
                rollin2();
        }
        for(int i=0; i<n; i++){
             for(int j=0; j<n; j++){
                 cout<<v[i][j]<<" ";
             }
             cout<<"\n";
        }
    }
}