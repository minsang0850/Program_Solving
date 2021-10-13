#include <iostream>
#include <vector>

using namespace std;

int n,studentCount;
vector<int> status;

bool inRange(int k, int num){
    if(k+num<=n && k-num>0)
        return true;
    else
        return false;
}
int main(){
    cin>>n;
    int input;
    status.push_back(-1);
    for(int i=0; i<n; i++){
        cin>>input;
        status.push_back(input);
    }

    cin>>studentCount;
    
    for(int i=0; i<studentCount; i++){
        int sex,num;
        cin>>sex>>num;
        if(sex==1){
            for(int j=1; j*num<=n; j++){
                status[j*num]=(status[j*num]+1)%2;
            }
        }
        else{
            int k=1;
            status[num]=((status[num])+1)%2;
            while(inRange(num,k)){
                status[num+k]=((status[num+k])+1)%2;
                status[num-k]=((status[num-k])+1)%2;
                k++;
            }
        }
        
    }

    int row=n/20;
    for(int i=0; i<row; i++){
        for(int j=1; j<21; j++){
            cout<<status[i*20+j]<<" ";
        }
        cout<<endl;
    }
    int column=n%20;
    for(int i=1; i<=column; i++){
        cout<<status[row*20+i]<<" ";
    }
}