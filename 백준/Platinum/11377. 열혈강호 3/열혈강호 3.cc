#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define P pair<int,int>
#define T tuple<long long int,int,int>
#define SIZE 1001

int n, m, l, p[SIZE], work[SIZE], num[SIZE];
vector<int> adj[SIZE];
bool chk[SIZE];

bool DFS(int from) {
    chk[from] = 1;
    for (auto to: adj[from]) {
        if (work[to] == -1 || (!chk[work[to]] && DFS(work[to]))) {
            p[from] = to, work[to] = from;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++) {
        int k, a;
        cin >> k;
        while (k--) {
            cin >> a;
            adj[i].push_back(a);
        }
    }
    fill(p, p + SIZE, -1);
    fill(work, work + SIZE, -1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        fill(chk, chk + SIZE, 0);
        if (DFS(i)) res++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        fill(chk, chk + SIZE, 0);
        if (DFS(i))
            res++, cnt++;
        if (cnt == l) break;
    }
    cout << res;
    return 0;
}
