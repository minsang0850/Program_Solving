#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
int n;
unordered_map<int,int> min_map;
unordered_map<int,int> max_map;

int get_max(string n){
    int size=n.size();
    int answer=0;
    for(int i=0; i<size; i++){  //1.홀수 개수
        if((n[i]-'0')%2!=0)
            answer++;
    }
    if(size==1){        //2.바로 종료
        max_map[stoi(n)]=answer;
        return answer;
    }
    if(size==2){        //3.두자리면 두개의 합으로 새로운 수
         int k=(n[0]-'0')+(n[1]-'0');
         max_map[stoi(n)]=answer+get_max(to_string(k));
        return max_map[stoi(n)];
    }
    string s1,s2,s3;
    int ans_tmp=0;
     for(int i=1; i<=size-2; i++){    //4. 세자리 수면 3개의 수 분할, 3개 합을 새로운 수
        s1=n.substr(0,i);
        for(int j=1; i+j<=size-1; j++){
            s2=n.substr(i,j);
            s3=n.substr(i+j,size-j-i);
            int k=stoi(s1)+stoi(s2)+stoi(s3);
            ans_tmp=max(ans_tmp,get_max(to_string(k)));
        }
    }
    answer+=ans_tmp;
    return answer;
}

int get_min(string n){
    int size=n.size();
    int answer=0;
    for(int i=0; i<size; i++){
        if((n[i]-'0')%2!=0)
            answer++;
    }
    if(size==1){
         min_map[stoi(n)]=answer;
         return answer;
    }
    if(size==2){
        int k=(n[0]-'0')+(n[1]-'0');
         min_map[stoi(n)]=answer+get_min(to_string(k));
        return min_map[stoi(n)];
    }
    string s1,s2,s3;
    int ans_tmp=9999;
    for(int i=1; i<=size-2; i++){    //4. 세자리 수면 3개의 수 분할, 3개 합을 새로운 수
        s1=n.substr(0,i);
        for(int j=1; i+j<=size-1; j++){
            s2=n.substr(i,j);
            s3=n.substr(i+j,size-j-i);
            int k=stoi(s1)+stoi(s2)+stoi(s3);
            ans_tmp=min(ans_tmp,get_min(to_string(k)));
        }
    }
    answer+=ans_tmp;
    return answer;
}

int main(){
    cin>>n;
    cout<<get_min(to_string(n))<<" ";
    cout<<get_max(to_string(n));
    return 0;
}