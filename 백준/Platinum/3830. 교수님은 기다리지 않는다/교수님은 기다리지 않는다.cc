#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define SIZE 100'002

int n, m, p[SIZE];
ll dist[SIZE];

int find(int x) {
    if (p[x] == x) return x;
    int parent = find(p[x]);
    dist[x] += dist[p[x]];
    return p[x] = parent;
}

void merge(int a, int b, int w) {
    int rootA = find(a), rootB = find(b);
    if (rootA == rootB) return;
    dist[rootB] = dist[a] - dist[b] + w;
    p[rootB] = rootA;
    return;
}

int main() {
    fastio;
    while (1) {
        cin >> n >> m;
        if (!n && !m) break;
        for (int i = 1; i <= n; i++)
            p[i] = i, dist[i] = 0;
        while (m--) {
            char c;
            int a, b, w;
            cin >> c;
            if (c == '!') {
                cin >> a >> b >> w;
                merge(a, b, w);
            } else {
                cin >> a >> b;
                if (find(a) != find(b)) cout << "UNKNOWN\n";
                else cout << dist[b] - dist[a] << '\n';
            }
        }
    }
    return 0;
}
