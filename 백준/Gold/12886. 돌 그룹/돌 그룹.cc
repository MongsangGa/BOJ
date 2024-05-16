#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

struct D {
    int a, b, c;
};

bool dp[1505][1505];
int res;
queue<D> q;

int main() {
    fastio;
    D d;
    cin >> d.a >> d.b >> d.c;
    if ((d.a + d.b + d.c) % 3) {
        cout << 0;
        return 0;
    }
    q.push(d);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        sort((int *) &cur, (int *) &cur + 3);
        if (cur.a == cur.b && cur.b == cur.c) {
            res = 1;
            break;
        }
        if (dp[cur.a][cur.b]) continue;
        dp[cur.a][cur.b] = true;
        if (cur.a < cur.b) q.push({cur.a * 2, cur.b - cur.a, cur.c});
        if (cur.a < cur.c) q.push({cur.a * 2, cur.b, cur.c - cur.a});
        if (cur.b < cur.c) q.push({cur.a, cur.b * 2, cur.c - cur.b});
    }
    cout << res;
    return 0;
}
