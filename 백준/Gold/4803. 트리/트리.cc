#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
const int SIZE = 502;

int t = 1, v, e, a, b, p[SIZE], chk[SIZE];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    p[v] = u;
}

int main() {
    fastio;
    while (t) {
        cin >> v >> e;
        if (!v && !e) break;
        fill(chk, chk + v + 1, 0);
        for (int i = 1; i <= v; i++) p[i] = i;
        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a == b || (chk[a] || chk[b])) {
                chk[a] = chk[b] = 1;
                continue;
            }
            merge(a, b);
        }
        int res = 0;
        for (int i = 1; i <= v; i++) {
            int x = find(i);
            if (!chk[x]) {
                res++;
                chk[x] = 1;
            }
        }
        if (!res) printf("Case %d: No trees.\n", t);
        else if (res == 1) printf("Case %d: There is one tree.\n", t);
        else printf("Case %d: A forest of %d trees.\n", t, res);
        t++;
    }
    return 0;
}
