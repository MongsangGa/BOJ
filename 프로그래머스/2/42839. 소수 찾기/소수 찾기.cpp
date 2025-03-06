#include <bits/stdc++.h>
using namespace std;

bool vis[10];
string number;
vector<int> res;

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i=2;i*i<=n;i++)
        if(!(n%i)) return false;
    return true;
}

void DFS(int cnt, string now) {
    if(cnt > number.size()) 
        return;
    if(cnt) 
        res.push_back(stoi(now));
    for(int i=0;i<number.size();i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        DFS(cnt + 1, now + number[i]);
        vis[i] = 0;
    }
}

int solution(string numbers) {
    number = numbers;
    DFS(0, "");
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    int answer = 0;
    for(int r:res)
        if(isPrime(r))
            ++answer;
    return answer;
}