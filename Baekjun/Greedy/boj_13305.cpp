#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> v;
vector<long long> price;
vector<pair<long, long>> vpair;
int main(){
    long long answer=0;
    cin>>N;
    for(int i=0; i<N-1; i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        price.push_back(k);
     vpair.push_back({k,i});
    }
    sort(vpair.begin(),vpair.end());
    int min=0;
    int check=N-1;
    for(int i=0; i<N; i++){
        if(vpair[i].first>min && vpair[i].second<check){
            int dist=0;
            for(int j=vpair[i].second; j<check; j++)
                dist+=v[j];
            answer+=dist * vpair[i].first;
            min=vpair[i].first;
            check=vpair[i].second;
            if(vpair[i].second==0){
                cout<<answer;
                return 0;
            }
                
        }
    }

}