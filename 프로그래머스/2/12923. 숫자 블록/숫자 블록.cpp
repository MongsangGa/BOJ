#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1'000'000'000

ll f(ll& num) {
    if (num == 1) return 0;
    long long i = 2, res = 1;
    while (i * i <= num) {
        if (num % i == 0) {
            res = i;
            if (num / i <= 10000000) return (num / i);
        }
        i++;
    }
    return res;
}

vector<int> solution(ll begin, ll end) {
    vector<int> answer;
    for (; begin <= end; begin++) {
        answer.push_back(f(begin));
    }
    return answer;
}   