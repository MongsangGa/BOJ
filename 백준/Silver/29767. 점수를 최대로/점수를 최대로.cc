#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define S 300'001

struct info {
    ll v;
    int idx;
};

int n, k, arr[S];
bool vis[S];
info psum[S];
ll res;

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    psum[0] = {arr[0], 0};
    for (int i = 1; i < n; i++)
        psum[i] = {psum[i - 1].v + arr[i], i};
    sort(psum, psum + n, [&](const info &a, const info &b) {
        if (a.v == b.v) return a.idx < b.idx;
        return a.v > b.v;
    });
    for (int i = 0; i < k; i++) vis[psum[i].idx] = 1;
    for (int i = 0; i < n; i++) {
        res += (ll) arr[i] * (ll) k;
        if (vis[i]) --k;
    }
    cout << res;
    return 0;
}