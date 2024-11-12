#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
#define SIZE 100'001
#define INF (int)1e9

struct NODE {
    int l, r, m, a;
};

int n, m;
NODE tree[SIZE * 4];

NODE merge(NODE &front, NODE &back) {
    NODE N{};
    N.l = max(front.l, front.a + back.l);
    N.r = max(back.r, back.a + front.r);
    N.m = max({front.m, back.m, front.r + back.l});
    N.a = front.a + back.a;
    return N;
}

NODE update(int idx, int v, int node = 1, int s = 1, int e = n) {
    if (idx < s || idx > e) return tree[node];
    if (s == e) return tree[node] = {v, v, v, v,};
    int mid = (s + e) / 2;
    NODE front = update(idx, v, node * 2, s, mid);
    NODE back = update(idx, v, node * 2 + 1, mid + 1, e);
    return tree[node] = merge(front, back);
}

NODE query(int qs, int qe, int node = 1, int s = 1, int e = n) {
    if (e < qs || s > qe) return {-INF, -INF, -INF, 0};
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    NODE front = query(qs, qe, node * 2, s, mid);
    NODE back = query(qs, qe, node * 2 + 1, mid + 1, e);
    return merge(front, back);
}


int main() {
    fastio;
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        update(i, x);
    }
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << query(s, e).m << '\n';
    }
    return 0;
}
