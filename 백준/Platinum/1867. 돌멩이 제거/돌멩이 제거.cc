#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define P pair<int,int>
#define T tuple<long long int,int,int>
#define SIZE 502

int n, m, l[SIZE], r[SIZE], res;
bool chk[SIZE];
vector<int> adj[SIZE];

bool dfs(int from) {
    chk[from] = 1;
    for (auto to: adj[from]) {
        if (r[to] == -1 || (!chk[r[to]] && dfs(r[to]))) {
            r[to] = from, l[from] = to;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    fill(l, l + SIZE, -1), fill(r, r + SIZE, -1);
    for (int i = 1; i <= n; i++) {
        fill(chk, chk + SIZE, 0);
        if (dfs(i))
            res++;
    }
    cout << res;
    return 0;
}
