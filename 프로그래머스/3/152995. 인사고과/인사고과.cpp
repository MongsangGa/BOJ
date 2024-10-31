#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    pair<int,int> wanho = {scores[0][0], scores[0][1]};
    sort(scores.begin(), scores.end(), [&](const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    int maxScore = -1;
    for(auto now:scores) {
        if(maxScore < now[1]) 
            maxScore = now[1];
        else if(maxScore > now[1]) {
            if(wanho.first == now[0] && wanho.second == now[1])
                return -1;
            continue;
        }
        if(wanho.first + wanho.second < now[0] + now[1])
            answer++;
    }
    return answer;
}