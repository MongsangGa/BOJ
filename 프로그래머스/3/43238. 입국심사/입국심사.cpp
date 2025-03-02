#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solution(int n, vector<int> times) {
    ll answer = 0;
    sort(times.begin(), times.end());
    ll s = 1, e = (ll)times.back() * n;
    while(s <= e) {
        ll mid = (s + e) / 2;
        ll tmp = 0;
        for(int t:times) 
            tmp += mid/t;
        if(tmp >= n) 
            e = mid - 1, answer = mid;
        else 
            s = mid + 1;
    }
    return answer;
}