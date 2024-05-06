#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 10'002

struct Tree {
    int x = -1, y = -1;
};

int n, parent[SIZE], width = 1, res, resI;
vector<vector<int>> v(SIZE); // level width
Tree t[SIZE];

void DFS(int node, int level) {
    Tree cur = t[node];
    if (cur.x != -1) DFS(cur.x, level + 1);
    v[level].push_back(width++);
    if (cur.y != -1) DFS(cur.y, level + 1);
}

int main() {
    fastio;
    int rootN, leafN;
    cin >> n;
    fflush(stdin);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b == -1 && c == -1) leafN = a;
        if (b != -1) parent[b] = a;
        if (c != -1) parent[c] = a;
        t[a] = {b, c};
    }
    rootN = leafN;
    while (parent[rootN])
        rootN = parent[rootN];
    DFS(rootN, 1);
    for (int i = 1; i < SIZE; i++) {
        if (v[i].empty()) continue;
        int ans = *(v[i].end() - 1) - v[i][0] + 1;
        if (res < ans) res = ans, resI = i;
    }
    cout << resI << ' ' << res;
    return 0;
}
