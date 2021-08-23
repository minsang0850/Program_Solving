#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> stk;
    int N; cin>>N;

    for(int i=0; i<N; i++){
        string cmd;
        cin>>cmd;
        if(cmd=="push"){
            int num;
            cin>>num;
            stk.push(num);
        }
        else if(cmd=="pop"){
            if(stk.empty())
                cout<<"-1\n";
            else{
                cout<<stk.top()<<"\n";
                stk.pop();
            }
        }
        else if(cmd=="size"){
            cout<<stk.size()<<"\n";
        }
        else if(cmd=="empty"){
            if(stk.empty())
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if(cmd=="top"){
            if(stk.empty())
                cout<<"-1\n";
            else{
                cout<<stk.top()<<"\n";
            }
        }     
    }
     return 0;
}