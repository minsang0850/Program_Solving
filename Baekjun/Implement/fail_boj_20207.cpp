#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> calender;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first)
        return true;
    else if(a.first==b.first){
        if(a.second>=b.second){
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

int main(){
    int answer=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        calender.push_back({s,e});
    }
    sort(calender.begin(),calender.end(),cmp);
    
    int start=calender[0].first;
    int end=calender[0].second;
    vector<pair<int,int>> v;
    v.push_back(calender[0]);
    for(int i=1; i<n; i++){
        if(calender[i].first<=end){
            end=max(calender[i].second,end);
            int j=0;

            for(j=0; j<v.size(); j++){
                if(v[j].second<calender[i].first)
                    break;
            }
            if(j<v.size()){
                v[j].second=calender[i].second;
            }
            else{
                v.push_back(calender[i]);
            }
        }
        else{
            answer+=(end-start+1)*v.size();
            v.clear();
            start=calender[i].first;
            end=calender[i].second;
            v.push_back(calender[i]);
        }
    }
    answer+=(end-start+1)*v.size();
    cout<<answer;
}