#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
vector<pair<int,int>> v;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(auto i:tangerine) m[i]++;
    for(auto i:m) v.push_back({i.second, i.first});
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        ++answer;
        k -= v[i].first;
        if(k <= 0) break;
    }
    return answer;
}