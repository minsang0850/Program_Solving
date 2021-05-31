#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first>b.first;
}

bool cmp_map_value(pair<string,int> a, pair<string,int> b){
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string,vector<pair<int,int>>> genre_playlist;  //장르와 수록곡
    unordered_map<string,int> genre_play_cnt;   //장르와 총 재생횟수
    vector<pair<string,int>> genre_play_cnt_v;  
    for(int i=0; i<genres.size(); i++){
        genre_playlist[genres[i]].push_back(make_pair(plays[i],i));
        genre_play_cnt[genres[i]]+=plays[i];
    }
    for(auto &k : genre_playlist){
        sort(k.second.begin(),k.second.end(),cmp);  //장르내 재생횟수 정렬
    }
    genre_play_cnt_v.assign(genre_play_cnt.begin(),genre_play_cnt.end());
    sort(genre_play_cnt_v.begin(),genre_play_cnt_v.end(),cmp_map_value);
    for(int i=0; i<genre_play_cnt_v.size(); i++){
        string s=genre_play_cnt_v[i].first;
        for(int j=0; (j<genre_playlist[s].size())&&j<2; j++){
            answer.push_back(genre_playlist[s][j].second);
        }
    }
    return answer;
}