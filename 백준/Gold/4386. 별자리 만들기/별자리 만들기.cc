#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 102

int n, cnt, p[SIZE];
double res;
vector<pair<double, double>> board;
vector<tuple<double, int, int>> adj;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    p[v] = u;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        board.push_back({x, y});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double dis = sqrt(pow((board[i].first - board[j].first), 2) + pow((board[i].second - board[j].second), 2));
            adj.push_back({dis, i, j});
        }
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(adj.begin(), adj.end());
    for (int i = 0; i < n * n; i++) {
        auto [cost, a, b] = adj[i];
        if (find(a) == find(b)) continue;
        merge(a, b);
        res += cost, cnt++;
        if (cnt == n - 1) break;
    }
    cout.precision(3);
    cout << res;
    return 0;
}
