#include <bits/stdc++.h>
using namespace std;

int res = 1e9;

int solution(int n, vector<int> weak, vector<int> dist) {
    int ws = weak.size(), ds = dist.size();
    for(int i=0;i<ws-1;i++)
        weak.push_back(weak[i] + n);
    sort(dist.begin(), dist.end());
    do {
        for(int i=0;i<ws;i++) {
            int st = weak[i], en = weak[ws+i-1];
            for(int j=0;j<ds;j++) {
                st += dist[j];
                if(st >= en) {
                    res = min(res, j+1);
                    break;
                }
                int nxt = upper_bound(weak.begin(), weak.end(), st) - weak.begin();
                st = weak[nxt];
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    return (res==1e9) ? -1 : res;
}