#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int camera = routes[0][1];
    for(int i=1;i<routes.size();i++) {
        if(routes[i][1] < camera) camera = routes[i][1];
        else if(routes[i][0] > camera) ++answer, camera = routes[i][1];
    }
    return answer;
}