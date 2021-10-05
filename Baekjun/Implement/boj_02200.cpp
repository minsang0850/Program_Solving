#include <iostream>

using namespace std;

int n;
int arr[10001];

int main(){
    int answer=0;
    cin>>n;
    for(int i=n; i>=0; i--){
        cin>>arr[i];
    }
    for(int i=n; i>0; i--){
        if(i==n){
            answer++;
            continue;
        }
        else if(arr[i]==0){
            answer+=2;
            continue;
        }
        answer++;       //+
        while(arr[i]>0){    //내 자릿수 더함
            answer++;
            //cout<<arr[i]%10;
            arr[i]/=10;
        }
         if(i!=n){
            answer+=2;          //*x
           // cout<<"*x";
         }
    }
    //cout<<"+";
    if(arr[0]!=0)
        answer++;
    while(arr[0]>0){
        answer++;
        //cout<<"1";
        arr[0]/=10;
    }
    answer++;
    //cout<<"="<<endl;
    cout<<answer<<endl;
}