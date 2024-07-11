#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
const int SIZE = 100'002;
int n, m, a, b, dep[SIZE] = {-1}, arr[SIZE][20];
int max_level = floor(log2(SIZE));
vector<int> adj[SIZE];

void init(int now, int parent) {
    dep[now] = dep[parent] + 1;
    arr[now][0] = parent;
    for (int i = 1; i <= max_level; i++) {
        int tmp = arr[now][i - 1];
        arr[now][i] = arr[tmp][i - 1];
    }
    for (auto nxt: adj[now]) {
        if (nxt == parent) continue;
        init(nxt, now);
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init(1, 0);
    cin >> m;
    while (m--) {
        cin >> a >> b;
        if (dep[a] != dep[b]) {
            if (dep[a] > dep[b]) swap(a, b);
            for (int i = max_level; i >= 0; i--)
                if (dep[a] <= dep[arr[b][i]])
                    b = arr[b][i];
        }
        int res = a;
        if (a != b) {
            for (int i = max_level; i >= 0; i--) {
                if (arr[a][i] != arr[b][i])
                    a = arr[a][i], b = arr[b][i];
                res = arr[a][i];
            }
        }
        cout << res << '\n';
    }
    return 0;
}
