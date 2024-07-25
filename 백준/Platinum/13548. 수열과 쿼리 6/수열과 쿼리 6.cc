#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE (int)(1e5 + 2)

int n, m, sqrtN, now, cnt[SIZE], ccnt[SIZE], arr[SIZE], res[SIZE];
struct Q {
    int idx, s, e;
};
Q q[SIZE];

void pl(int s, int e) {
    for (int i = s; i <= e; i++) {
        --ccnt[cnt[arr[i]]];
        ++cnt[arr[i]];
        ++ccnt[cnt[arr[i]]];
        if (now < cnt[arr[i]])
            now = cnt[arr[i]];
    }
}

void mi(int s, int e) {
    for (int i = s; i <= e; i++) {
        --ccnt[cnt[arr[i]]];
        --cnt[arr[i]];
        ++ccnt[cnt[arr[i]]];
        if (!ccnt[now]) --now;
    }
}

int main() {
    fastio;
    cin >> n;
    sqrtN = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].s >> q[i].e;
        q[i].idx = i;
    }
    sort(q + 1, q + 1 + m, [&](const Q &a, const Q &b) {
        if (a.s / sqrtN != b.s / sqrtN) return a.s / sqrtN < b.s / sqrtN;
        return a.e < b.e;
    });
    ccnt[0] = n;
    int s = q[1].s, e = q[1].e;
    for (int i = s; i <= e; i++) {
        --ccnt[cnt[arr[i]]];
        ++cnt[arr[i]];
        ++ccnt[cnt[arr[i]]];
        if (now < cnt[arr[i]]) now = cnt[arr[i]];
    }
    res[q[1].idx] = now;
    for (int i = 2; i <= m; i++) {
        if (s < q[i].s) mi(s, q[i].s - 1);
        if (s > q[i].s) pl(q[i].s, s - 1);
        if (e < q[i].e) pl(e + 1, q[i].e);
        if (e > q[i].e) mi(q[i].e + 1, e);
        s = q[i].s, e = q[i].e, res[q[i].idx] = now;
    }
    for (int i = 1; i <= m; i++) cout << res[i] << '\n';
    return 0;
}
