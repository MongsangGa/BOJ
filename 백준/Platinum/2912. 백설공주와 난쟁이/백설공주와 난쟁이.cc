#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 300'001


int n, c, m, arr[SIZE], stree[SIZE * 4];
vector<int> idx[SIZE];

void setTree(int node, int s, int e) {
    if (s == e) {
        stree[node] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    setTree(node * 2, s, mid);
    setTree(node * 2 + 1, mid + 1, e);
    int v = stree[node * 2];
    int cnt =
            upper_bound(idx[v].begin(), idx[v].end(), e) - lower_bound(idx[v].begin(), idx[v].end(), s) + 1;
    if (cnt > (e - s + 1) / 2) {
        stree[node] = v;
        return;
    }
    v = stree[node * 2 + 1];
    cnt = upper_bound(idx[v].begin(), idx[v].end(), e) - lower_bound(idx[v].begin(), idx[v].end(), s) + 1;
    if (cnt > (e - s + 1) / 2) {
        stree[node] = v;
        return;
    }
    stree[node] = -1;
}

int query(int node, int s, int e, int qs, int qe) {
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) {
        if (stree[node] == -1) return 0;
        int cnt = upper_bound(idx[stree[node]].begin(), idx[stree[node]].end(), qe) -
                  lower_bound(idx[stree[node]].begin(), idx[stree[node]].end(), qs);
        if (cnt > (qe - qs + 1) / 2) return stree[node];
        else return 0;
    }
    int mid = (s + e) / 2;
    int l = query(node * 2, s, mid, qs, qe);
    if (l > 0) return l;
    int r = query(node * 2 + 1, mid + 1, e, qs, qe);
    if (r > 0) return r;
    return 0;
}

int main() {
    fastio;
    cin >> n >> c;
    for (int i = 1, x; i <= n; i++) {
        cin >> arr[i];
        idx[arr[i]].push_back(i);
    }
    for (int i = 1; i <= c; i++)
        sort(idx[i].begin(), idx[i].end());
    setTree(1, 1, n);
    cin >> m;
    while (m--) {
        int qs, qe;
        cin >> qs >> qe;
        int res = query(1, 1, n, qs, qe);
        if (res) cout << "yes " << res << '\n';
        else cout << "no\n";
    }
    return 0;
}
