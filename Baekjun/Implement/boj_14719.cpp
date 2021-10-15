#include <iostream>
#include <vector>

using namespace std;

int h,w;
//vector<vector<int>> v;
int v[501];
int main(){
    cin>>h>>w;
    //v.resize(h,vector<int>(w));
    for(int i=0; i<w; i++){
        cin>>v[i];
    }
    int answer=0;
    int tmp=0;
    int left=0;
    //int right=500;
    //v[500]=0;
    for(int i=1; i<w; i++){
            int small=min(v[left],v[i]);
            for(int j=left; j<i; j++){
                if(small-v[j]>0){
                    answer+=small-v[j];
                    v[j]=small;
                }
            }
            if(v[left]<=v[i])
                left=i;
        }
    
   // cout<<"left:"<<left<<" right:"<<right<<endl;
    
    cout<<answer;
}