#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(5,vector<int>(5));

bool isBingo(){
    int answer=0;
    for(int i=0; i<5; i++){
        int check=0;
        for(int j=0; j<5; j++){
            if(v[i][j]==-1)
                check++;
        }
        if(check==5)
            answer++;
    }
    for(int i=0; i<5; i++){
        int check=0;
        for(int j=0; j<5; j++){
            if(v[j][i]==-1)
                check++;
        }
        if(check==5)
            answer++;
    }

    int check=0;
    for(int i=0; i<5; i++){
        if(v[i][i]==-1)
            check++;
    }
    if(check==5)
        answer++;

    check=0;
    for(int i=0; i<5; i++){
        if(v[i][4-i]==-1)
            check++;
    }
    if(check==5)
        answer++;

    if(answer>=3)
        return true;
    else return false;
}

int main(){
    int input;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>v[i][j];
        }
    }
    for(int k=0; k<25; k++){
        int a;
        cin>>a;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(a==v[i][j])
                    v[i][j]=-1;
            }
        }
        if(isBingo()){
            cout<<k+1;
            return 0;
        }
    }
}