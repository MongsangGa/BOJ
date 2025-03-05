#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int now = 1, sidx = 0;
    while(now <= n) {
        if(now >= stations[sidx] - w && now <= stations[sidx] + w) {
            now = stations[sidx] + w + 1;
            ++sidx;
        }
        else {
            now += w * 2 + 1;
            ++answer;
        }
    }
    return answer;
}