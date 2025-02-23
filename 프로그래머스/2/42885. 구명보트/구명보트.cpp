#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int res = 0, s = 0, e = people.size() - 1;
    sort(people.begin(), people.end());
    while(s<=e) {
        if(people[s] + people[e] <= limit) ++s;
        --e, ++res;
    }
    return res;
}