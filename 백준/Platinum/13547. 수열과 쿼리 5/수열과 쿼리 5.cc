#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE (int)(1e5 + 2)
#define ll long long

struct Q {
    ll idx, s, e;
};

ll n, m, sqrtN, now, arr[SIZE], cnt[SIZE * 10], res[SIZE];
Q query[SIZE];

void pi(ll s, ll e) {
    for (ll i = s; i <= e; i++) {
        if (!cnt[arr[i]]) ++now;
        ++cnt[arr[i]];
    }
}

void mi(ll s, ll e) {
    for (ll i = s; i <= e; i++) {
        --cnt[arr[i]];
        if (!cnt[arr[i]]) --now;
    }
}

int main() {
    fastio;
    cin >> n;
    sqrtN = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> query[i].s >> query[i].e;
        query[i].idx = i;
    }
    sort(query + 1, query + 1 + m, [&](const Q &a, const Q &b) {
        if (a.s / sqrtN != b.s / sqrtN) return a.s / sqrtN < b.s / sqrtN;
        return a.e < b.e;
    });
    for (ll i = query[1].s; i <= query[1].e; i++) {
        if (!cnt[arr[i]]) ++now;
        ++cnt[arr[i]];
    }
    res[query[1].idx] = now;
    ll l = query[1].s, r = query[1].e;
    for (int i = 2; i <= m; i++) {
        if (l < query[i].s) mi(l, query[i].s - 1);
        if (l > query[i].s) pi(query[i].s, l - 1);
        if (r < query[i].e) pi(r + 1, query[i].e);
        if (r > query[i].e) mi(query[i].e + 1, r);
        l = query[i].s, r = query[i].e, res[query[i].idx] = now;
    }
    for (int i = 1; i <= m; i++) cout << res[i] << '\n';
    return 0;
}
