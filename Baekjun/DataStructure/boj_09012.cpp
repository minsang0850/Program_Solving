#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        stack<int> stk;
        string str; cin>>str;
        int size=str.size();

        bool answer=true;
        for(int i=0; i<size; i++){
            if(str[i]=='(')
                stk.push(1);
            else{
                if(stk.empty()){
                    answer=false;
                    break;
                }
                else
                    stk.pop();
            }
        }
        if(!stk.empty())
            answer=false;
        

        if(answer)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
     return 0;
}