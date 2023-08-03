#include <bits/stdc++.h>

using namespace std;

#define MAX 100'001

int n, S, E, res;
vector<pair<int, int>> v[MAX];

void solve(int now, int prev, int M, int total) {
    if (now == E) {
        res = total - M;
        return;
    }
    for (auto [nxt, cost]: v[now]) {
        if (nxt != prev)
            solve(nxt, now, max(M, cost), total + cost);
    }
}

int main() {
    cin >> n >> S >> E;
    for (int i = 0; i < n - 1; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({b, cost});
        v[b].push_back({a, cost});
    }
    solve(S, 0, 0, 0);
    cout << res;
    return 0;
}