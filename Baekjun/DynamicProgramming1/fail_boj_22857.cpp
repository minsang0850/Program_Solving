#include <iostream>
#include <vector>

using namespace std;

int N,K;
vector<int> v;
int odd[50001]; //odd[i]=0~i까지 홀수의 개수

int main(){
    cin>>N>>K;
    int sum=0;
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        if(tmp%2==1)
            sum++;
        odd[i]=sum;        
    }
    int start=0;
    int answer=0;
    if(sum<=K)
        answer=N;
    for(int i=0; i<N; i++){
        if(odd[i]-odd[start]<=K)
            answer=max(answer,i-start-(odd[i]-odd[start]));
        else{
            while(odd[i]-odd[start]>K)
                start++;
            answer=max(answer,i-start-(odd[i]-odd[start]));
        }
    }
    cout<<answer;
    return 0;
}