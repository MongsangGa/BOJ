#include <bits/stdc++.h>
using namespace std;

int n, targets, res;
vector<int> number;

void DFS(int now, int depth) {
    if(depth == n) {
        if(now == targets) ++res;
        return;
    }
    DFS(now + number[depth], depth+1);
    DFS(now - number[depth], depth+1);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size(), number = numbers, targets = target;
    DFS(0,0);
    return res;
}