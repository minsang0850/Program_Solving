#include <iostream>

using namespace std;

int n;
int arr[1001][1001];
int value;
int answera,answerb;
void solution(int k,int a, int b){
    if(k==1){
        arr[a][b]=1;
        if(value==1){
            answera=a+1;
            answerb=b+1;
        }
        return;
    }
    int num=k*k;
    for(int i=0; i<k; i++){
        if(num==value){
            answera=a+i+1;
            answerb=b+1;
        }
        arr[a+i][b]=num--;
    }
    for(int i=1; i<k; i++){
        if(num==value){
            answera=a+k;
            answerb=b+i+1;
        }
        arr[a+k-1][b+i]=num--;
    }
    for(int i=1; i<k; i++){
        if(num==value){
            answera=a+k-i;
            answerb=b+k;
        }
        arr[a+k-1-i][b+k-1]=num--;
    }
    for(int i=1; i<k-1; i++){
        if(num==value){
            answera=a+1;
            answerb=b+k-i;
        }
        arr[a][b+k-1-i]=num--;
    }
    solution(k-2,a+1,b+1);
}
int main(){
    cin>>n;
    cin>>value;
    solution(n,0,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<answera<<" "<<answerb;
}