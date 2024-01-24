#include <bits/stdc++.h>

using namespace std;

int n, maxN, maxV, chk[10'001];
vector<pair<int, int>> v[10'001];

void dfs(int node, int val) {
    for (int i = 0; i < v[node].size(); i++) {
        auto nxt = v[node][i];
        if (chk[nxt.first]) continue;
        chk[nxt.first] = 1;
        if (val + nxt.second > maxV) maxV = val + nxt.second, maxN = nxt.first;
        dfs(nxt.first, val + nxt.second);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    n--;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    chk[1] = 1;
    dfs(1, 0);
    memset(chk, 0, sizeof(chk));
    chk[maxN] = 1;
    dfs(maxN, 0);
    cout << maxV;
    return 0;
}
