#include <iostream>
#include <string>

using namespace std;


int main(){
    string board;
    cin>>board;
    int start=0;
    int size=board.size();
    for(int i=0; i<=size; i++){
        if(board[i]=='.' || i==size){
            if((i-start)%2!=0){
                cout<<-1;
                return 0;
            }
            else{
                if((i-start)%4==0){
                    for(int j=start; j<i; j++)
                        board[j]='A';
                }
                else{
                    for(int j=start; j<i-2; j++)
                        board[j]='A';
                    board[i-2]='B';
                    board[i-1]='B';
                }
            }
            start=i+1;
        }
    }
    cout<<board;
}