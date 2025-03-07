#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int ans = brown+yellow;
    for(int i=3;i<brown;i++) {
        if(ans%i) continue; 
        int j = ans/i;
        if(i>=j) 
            if(brown==(i-2)*2+(j*2)) 
                return vector<int>{i,j};
        else
            if(brown==(j-2)*2+(i*2))
                return vector<int>{j,i};
    }
    return vector<int>{0,0};
}