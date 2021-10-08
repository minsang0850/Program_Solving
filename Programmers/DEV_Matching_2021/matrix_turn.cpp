#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> board;

int spin(int a, int b, int aa, int bb){
    int save=board[a][b];
    int answer=save;
    for(int i=a; i<aa; i++){
        board[i][b]=board[i+1][b];
        if(answer>board[i][b])
            answer=board[i][b];
    }
    for(int i=b; i<bb; i++){
        board[aa][i]=board[aa][i+1];
        if(answer>board[aa][i])
            answer=board[aa][i];
    }
    for(int i=aa; i>a; i--){
        board[i][bb]=board[i-1][bb];
        if(answer>board[i][bb])
            answer=board[i][bb];
    }
    for(int i=bb; i>b; i--){
        int k=b+1;
        k--;
        if(i==k+1){
            board[a][b+1]=save;
            return answer;
        }

        board[a][i]=board[a][i-1];
        if(answer>board[a][i])
            answer=board[a][i];
    }
    board[a][b+1]=save;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int size = queries.size();
    for(int i=0; i<rows; i++){
        vector<int> tmp;
        for(int j=0; j<columns; j++){
            tmp.push_back(i*columns+j+1);
        }
        board.push_back(tmp);
    }

    for(int i=0; i<size; i++){
        int a,b,aa,bb;
        a=queries[i][0]-1;
        b=queries[i][1]-1;
        aa=queries[i][2]-1;
        bb=queries[i][3]-1;
        int k=0;
        k = spin(a,b,aa,bb);
        answer.push_back(k);
    }
    return answer;
}