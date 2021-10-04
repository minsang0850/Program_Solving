#include <iostream>
#include <vector>

using namespace std;

int N,X;
vector<int> v;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>X;
    int answer=0;
    int k;
    int sum=0;
     int sec=1;
    for(int i=0; i<X; i++){
        cin>>k;
        sum+=k;
        v.push_back(k);
    }   
    answer=sum;
   
    for(int i=X; i<N; i++){
        cin>>k;
        sum+=k;
        sum-=v[i-X];
        v.push_back(k);
        //cout<<sum<<endl;
        if(answer<sum){
            answer=sum;
            sec=1;
        }
        else if(answer==sum)
            sec++;
    }
    if(answer!=0)
        cout<<answer<<"\n"<<sec;
    else
        cout<<"SAD";
}