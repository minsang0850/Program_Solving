#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> num;
vector<string> sign;
int main(){
    string str;
    cin>>str;
    int size=str.size();
    string num_str;
    for(int i=0; i<size; i++){
        if(str[i]=='*' ||str[i]=='/' ||str[i]=='+' ||str[i]=='-' ){
            if(num.size()!=0){
                int a=stoi(num_str);
                num.push_back(a);
            }
            if(str[i]=='+')
                sign.push_back("+");
            else if(str[i]=='-')
                sign.push_back("-");
            else if(str[i]=='*')
                sign.push_back("*");
            else if(str[i]=='/')
                sign.push_back("/");
        }
        else{
            num_str+=str[i];
        }
    }
     num.push_back(stoi(num_str));
}