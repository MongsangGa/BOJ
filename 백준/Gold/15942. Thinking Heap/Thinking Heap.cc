#include <bits/stdc++.h>

using namespace std;

#define SIZE 200'001
int n, k, p, arr[SIZE], upNum, downNum;
queue<int> res;

void UP() {
    int target = p;
    vector<int> v;
    while (target >>= 1) v.push_back(target);
    if (v.size() >= k) {
        cout << "-1";
        exit(0);
    }
    reverse(v.begin(), v.end());
    for (auto i: v) arr[i] = ++upNum;
}

void DFS(int x) {
    arr[x] = downNum--;
    if (x * 2 <= n) DFS(x * 2);
    if (x * 2 + 1 <= n) DFS(x * 2 + 1);
}

void DOWN() {
    downNum = n;
    if (p * 2 <= n) DFS(p * 2);
    if (p * 2 + 1 <= n) DFS(p * 2 + 1);
    if (downNum < k) {
        cout << "-1";
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> p;
    arr[p] = k;
    UP();
    DOWN();
    for (int i = upNum + 1; i <= downNum; i++) {
        if (i == k) continue;
        res.push(i);
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i]) continue;
        arr[i] = res.front();
        res.pop();
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << '\n';
    return 0;
}
