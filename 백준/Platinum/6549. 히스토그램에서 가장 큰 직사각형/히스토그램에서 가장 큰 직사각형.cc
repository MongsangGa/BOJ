#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long
#define SIZE 100'002
#define INF (int)1e9

ll n, arr[SIZE], stree[SIZE * 4];

ll init(int node, int s, int e) {
    if (s == e) return stree[node] = s;
    int mid = (s + e) / 2;
    init(node * 2, s, mid);
    init(node * 2 + 1, mid + 1, e);
    if (arr[stree[node * 2]] <= arr[stree[node * 2 + 1]]) return stree[node] = stree[node * 2];
    else return stree[node] = stree[node * 2 + 1];
}

ll query(int node, int s, int e, int fs, int fe) {
    if (s > fe || e < fs) return INF;
    if (fs <= s && e <= fe) return stree[node];
    int mid = (s + e) / 2;
    ll m1 = query(node * 2, s, mid, fs, fe);
    ll m2 = query(node * 2 + 1, mid + 1, e, fs, fe);
    if (m1 == INF) return m2;
    else if (m2 == INF) return m1;
    else {
        if (arr[m1] <= arr[m2]) return m1;
        else return m2;
    }
}

ll get_area(int s, int e) {
    ll midx = query(1, 1, n, s, e);
    ll res = (e - s + 1) * arr[midx];
    if (midx - 1 >= s) res = max(res, get_area(s, midx - 1));
    if (midx + 1 <= e) res = max(res, get_area(midx + 1, e));
    return res;
}

int main() {
    fastio;
    while (1) {
        cin >> n;
        if (!n) break;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        init(1, 1, n);
        cout << get_area(1, n) << '\n';
    }
    return 0;
}
