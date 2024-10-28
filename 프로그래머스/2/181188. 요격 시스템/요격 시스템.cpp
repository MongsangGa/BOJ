#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0, preE = 0;
    sort(targets.begin(), targets.end());
    for(int i=0;i<targets.size();i++){
        int nowS = targets[i][0];
        int nowE = targets[i][1];
        if(preE > nowS) 
            preE = min(preE, nowE);
        else {
            ++answer;
            preE = nowE;
        }
    }
    return answer;
}