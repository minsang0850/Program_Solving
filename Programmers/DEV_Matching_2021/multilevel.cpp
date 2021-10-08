#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,int> up;
vector<int> v;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int size=enroll.size();
    answer.resize(size);
    v.resize(size);
    for(int i=0; i<size; i++)
        up[enroll[i]]=i;
    
    int sell_size=seller.size();
    
    for(int i=0; i<sell_size; i++){
        //num : 판매자 번호
        int num = up[seller[i]];    
        int value = amount[i]*100;
        //판매자 꼬신사람
        while(referral[num]!="-"){
            int jul = value/10;
            int mine = value-jul;
            answer[num]+=mine;
            if(jul!=0){
                num=up[referral[num]];
                value=jul;
            }
            else
                break;
        }
        if(referral[num]=="-"){
            int jul = value/10;
            int mine = value-jul;
            answer[num]+=mine;
        }
        
    }
    return answer;
}