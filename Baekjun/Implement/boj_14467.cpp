#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
vector<int> v;
vector<int> position;
int answer=0;

int main(){
    cin>>n;
    v.resize(11,-1);
    position.resize(11,-1);
    for(int i=0; i<n; i++){
        int num,pos;
        cin>>num>>pos;
        if(position[num]==-1){
            position[num]=pos;
            v[num]++;
        }
        else if(position[num]!=pos){
            position[num]=pos;
            v[num]++;
        }   
    }
    for(int i=1; i<11; i++){
        if(v[i]!=-1)
            answer+=v[i];
    }
    cout<<answer;
}