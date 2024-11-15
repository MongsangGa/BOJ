#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define S 100'001
#define INF (ll)(1e18+1)

struct NODE {
    ll l, r, m, a;

    NODE(ll l = 0,ll r = 0,ll m = 0,ll a = 0): l(l), r(r), m(m), a(a) {
    }
};

int n, q;
NODE stree[S * 4];

NODE merge(NODE &front, NODE &back) {
    NODE N{};
    N.l = max(front.l, front.a + back.l);
    N.r = max(back.r, back.a + front.r);
    N.m = max({front.m, back.m, front.r + back.l});
    N.a = front.a + back.a;
    return N;
}

NODE update(int idx, int v, int node = 1, int s = 1, int e = n) {
    if (idx < s || idx > e) return stree[node];
    if (s == e) return stree[node] = {v, v, v, v};
    int mid = (s + e) / 2;
    NODE front = update(idx, v, node * 2, s, mid);
    NODE back = update(idx, v, node * 2 + 1, mid + 1, e);
    return stree[node] = merge(front, back);
}

NODE query(int qs, int qe, int node = 1, int s = 1, int e = n) {
    if (e < qs || s > qe) return {-INF, -INF, -INF, 0};
    if (qs <= s && e <= qe) return stree[node];
    int mid = (s + e) / 2;
    NODE front = query(qs, qe, node * 2, s, mid);
    NODE back = query(qs, qe, node * 2 + 1, mid + 1, e);
    return merge(front, back);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        update(i, x);
    }
    cin >> q;
    for (int i = 0, x1, y1, x2, y2; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 >= x2) {
            NODE front = query(x1, x2 - 1);
            NODE mid = query(x2, y1);
            NODE back = query(y1 + 1, y2);
            cout << max({mid.m, front.r + mid.l, back.l + mid.r, front.r + mid.a + back.l}) << '\n';
        } else {
            NODE front = query(x1, y1);
            NODE mid = query(y1 + 1, x2 - 1);
            NODE back = query(x2, y2);
            cout << front.r + mid.a + back.l << '\n';
        }
    }
    return 0;
}

/*
 * 구간이 겹치지 않는 경우 : front.r + mid.a + back.l
 * 구간이 겹치는 경우 : max({mid.m, front.r + mid.a, back.l + mid.a, front.r + mid.a + back.l})
*/
