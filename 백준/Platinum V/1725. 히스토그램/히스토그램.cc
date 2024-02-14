#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define ll long long int
#define SIZE 100'001
#define INF (int)1e9

ll n, arr[SIZE], stree[SIZE * 4];

ll init(int node, int s, int e) {
    if (s == e) return stree[node] = s;
    int mid = (s + e) / 2;
    init(node * 2, s, mid), init(node * 2 + 1, mid + 1, e);
    if (arr[stree[node * 2]] <= arr[stree[node * 2 + 1]]) return stree[node] = stree[node * 2];
    else return stree[node] = stree[node * 2 + 1];
}

ll query(int node, int s, int e, int findS, int findE) {
    if (s > findE || e < findS) return -1;
    if (s >= findS && e <= findE) return stree[node];
    int mid = (s + e) / 2;
    ll mIdx1 = query(node * 2, s, mid, findS, findE), mIdx2 = query(node * 2 + 1, mid + 1, e, findS, findE);
    if (mIdx1 == -1) return mIdx2;
    else if (mIdx2 == -1) return mIdx1;
    else {
        if (arr[mIdx1] <= arr[mIdx2]) return mIdx1;
        else return mIdx2;
    }
}

ll get_min(int s, int e) {
    ll mIdx = query(1, 1, n, s, e);
    ll area = (e - s + 1) * arr[mIdx];
    if (mIdx - 1 >= s)
        area = max(area, get_min(s, mIdx - 1));
    if (mIdx + 1 <= e)
        area = max(area, get_min(mIdx + 1, e));
    return area;
}

int main() {
    fastio
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    cout << get_min(1, n);
    return 0;
}
