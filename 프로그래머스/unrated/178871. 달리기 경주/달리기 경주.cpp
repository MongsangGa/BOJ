#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m1;
    map<int, string> m2;
    for(int i=0;i<players.size();i++){
        m1[players[i]]=i;
        m2[i]=players[i];
    }
    for(int i=0;i<callings.size();i++){
        int index=m1[callings[i]];
        string name=m2[index-1];
        swap(m1[name],m1[m2[index]]);
        swap(m2[index],m2[index-1]);
    }
    for(auto s: m2)
        answer.push_back(s.second);
    return answer;
}