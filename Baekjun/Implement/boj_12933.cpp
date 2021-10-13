#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define cry "quack"

using namespace std;

vector<string> v;
string str;
int answer=0;

int main(){
    cin>>str;
    int size = str.size();
    for(int i=0; i<size; i++){
        if(str[i]=='q'){
            v.push_back("q");
        }
        else{
            int order=0;
            int j;
            for(j=1; j<5; j++){
                if(cry[j]==str[i])
                    break;
            }
            if(j==5){
                cout<<-1;
                return 0;
            }
            order=j;
            for(j=0; j<v.size(); j++){
                if(v[j].size()==order)
                    break;
            }
            if(j==v.size()){
                cout<<-1;
                return 0;
            }
            v[j].push_back(str[i]);
            answer=max(answer ,(int)v.size());
            if(order==4)
                v.erase(v.begin()+j);
        }
    }
    if(v.size()!=0){
        cout<<-1;
    }
    else{
        cout<<answer;
    }
    return 0;
}