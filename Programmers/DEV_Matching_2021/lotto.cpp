#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count=0;
    int zero=0;
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    for(int i=0; i<6; i++){
        if(lottos[i]==0)
            zero++;
        for(int j=0; j<6; j++){
            if(lottos[i]==win_nums[j])
                count++;
        }
    }
    int maxi=count+zero;
     if(maxi>=2)
        answer.push_back(7-maxi);
    else
        answer.push_back(6);
    if(count>=2)
        answer.push_back(7-count);
    else
        answer.push_back(6);
    return answer;
}