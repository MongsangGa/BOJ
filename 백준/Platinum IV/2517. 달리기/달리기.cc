#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 500'001

int n, arr[SIZE], stree[SIZE * 4];
vector<int> v;

int update(int node, int s, int e, int idx) {
    if (idx < s || idx > e) return stree[node];
    if (s == e) return stree[node] = 1;
    int mid = (s + e) / 2;
    return stree[node] = update(node * 2, s, mid, idx) + update(node * 2 + 1, mid + 1, e, idx);
}

int sum(int node, int s, int e, int findS, int findE) {
    if (s > findE || e < findS) return 0;
    if (s >= findS && e <= findE) return stree[node];
    int mid = (s + e) / 2;
    return sum(node * 2, s, mid, findS, findE) + sum(node * 2 + 1, mid + 1, e, findS, findE);
}

int main() {
    fastio
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i], v.push_back(arr[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        update(1, 0, n - 1, idx);
        cout << (i + 1) - sum(1, 0, n - 1, 0, idx - 1) << '\n';
    }
    return 0;
}
