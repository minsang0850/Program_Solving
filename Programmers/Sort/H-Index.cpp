#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    for(int i=0; i<citations.size(); i++){
        answer=max(answer,min(i+1,citations[i]));
    }
    return answer;
}