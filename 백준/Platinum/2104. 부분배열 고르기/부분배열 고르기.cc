#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define pii pair<ll,int>
#define sum first
#define MIN second
const int SIZE = 100'002;

int n;
ll arr[SIZE];
pii stree[SIZE * 4];

pii update(int node, int s, int e) {
    if (s == e) return stree[node] = {arr[s], s};
    int mid = (s + e) / 2;
    pii a = update(node * 2, s, mid), b = update(node * 2 + 1, mid + 1, e);
    return stree[node] = {a.sum + b.sum, (arr[a.MIN] > arr[b.MIN]) ? b.MIN : a.MIN};
}

pii query(int node, int s, int e, int fS, int fE) {
    if (s > fE || e < fS) return {0, 0};
    if (fS <= s && e <= fE) return {stree[node].sum, stree[node].MIN};
    int mid = (s + e) / 2;
    pii a = query(node * 2, s, mid, fS, fE), b = query(node * 2 + 1, mid + 1, e, fS, fE);
    return {a.sum + b.sum, (arr[a.MIN] > arr[b.MIN]) ? b.MIN : a.MIN};
}

ll getRes(int s, int e) {
    if (s == e) return arr[s] * arr[s];
    pii now = query(1, 1, n, s, e);
    ll res = now.sum * arr[now.MIN];
    if (now.MIN - 1 >= s) res = max(res, getRes(s, now.MIN - 1));
    if (now.MIN + 1 <= e) res = max(res, getRes(now.MIN + 1, e));
    return res;
}

int main() {
    fastio;
    cin >> n;
    fill(arr, arr + SIZE, 1e9);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    update(1, 1, n);
    cout << getRes(1, n);
    return 0;
}
