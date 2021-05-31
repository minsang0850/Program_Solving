#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second<b.second)
		return true;
	else if(a.second==b.second)
		return a.first<b.first;
	else
		return false;
}

vector<pair<int,int>> v;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
    	int start,end;
    	cin>>start>>end;
    	v.push_back({start,end});
    }
    sort(v.begin(),v.end(),cmp);
    int time=-1;
    int answer=0;
    for(int i=0; i<n; i++){
    	if(v[i].first>=time){
    		time=v[i].second;
    		answer++;
    	}
    }
    cout<<answer;
    return 0;
}