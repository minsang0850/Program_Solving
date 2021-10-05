#include <iostream>
#include <string>
using namespace std;

int n,count=0;

int calculate(int a, int b,string sign){
    if(sign=="S"){
        return a-b;
    }
    else if(sign=="M"){
        return a*b;
    }
    else if(sign=="U"){
        return a/b;
    }
    else{
        return a+b;
    }
}

int main(){
    cin>>n;
    string str;
    cin>>str;
    int size=str.size();
    string num_str="";
    int check=0;
    int value;
    int left;
    int right;
    string sign;
    for(int i=0; i<size; i++){
        if(str[i]=='S' ||str[i]=='M' ||str[i]=='U' ||str[i]=='P' ||str[i]=='C'){
            if(check==0){
                check=1;
                value=stoi(num_str);
                num_str="";
            }
            else if(check==1){
                int num=stoi(num_str);
                value=calculate(value,num,sign);
                num_str="";
            }
            else{
                check=1;
            }
            
            if(str[i]=='S'){
               sign="S";
            }
            else if(str[i]=='M'){
                sign="M";
            }
            else if(str[i]=='U'){
                sign="U";
            }
            else if(str[i]=='P'){
                sign="P";
            }
            else if(str[i]=='C'){
                count++;
                cout<<value<<" ";
                check=2;
            }
        }
        else{
            num_str+=str[i];
        }
    }
    if(count==0)
        cout<<"NO OUTPUT";
}