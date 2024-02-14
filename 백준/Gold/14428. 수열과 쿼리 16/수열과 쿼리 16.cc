#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 100'001
#define INF (int)1e9
struct Node {
    int arr = INF;
    int idx = INF;
};

bool operator<(const Node &a, const Node &b) {
    if (a.arr == b.arr) return a.idx < b.idx;
    return a.arr < b.arr;
}

int n, m, a, o, b, c;
vector<Node> stree(SIZE * 4);

Node query(int node, int s, int e, int findS, int findE) {
    if (s > findE || e < findS) return {INF, INF};
    if (findS <= s && e <= findE) return stree[node];
    int mid = (s + e) / 2;
    return min(query(node * 2, s, mid, findS, findE), query(node * 2 + 1, mid + 1, e, findS, findE));
}

Node update(int node, int s, int e, int idx, int cNum) {
    if (s > idx || e < idx) return stree[node];
    if (s == e) return stree[node] = {cNum, idx};
    int mid = (s + e) / 2;
    return stree[node] = min(update(node * 2, s, mid, idx, cNum), update(node * 2 + 1, mid + 1, e, idx, cNum));
}

int main() {
    fastio
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        update(1, 1, n, i, a);
    }
    cin >> m;
    while (m--) {
        cin >> o >> b >> c;
        if (o & 1) update(1, 1, n, b, c);
        else cout << query(1, 1, n, b, c).idx << '\n';
    }
    return 0;
}
