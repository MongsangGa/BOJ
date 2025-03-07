#include <bits/stdc++.h>
using namespace std;

int w, h;

int solution(vector<vector<int>> sizes) {
    int n = sizes.size();
    for(int i=0;i<n;i++) {
        if(sizes[i][0] > sizes[i][1]) w=max(w,sizes[i][0]), h=max(h,sizes[i][1]);
        else w=max(w,sizes[i][1]), h=max(h,sizes[i][0]);
    }
    return w*h;
}