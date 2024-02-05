#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 100'001

int n, k, v[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n >> k;
    v[n] = 1;
    q.push(n);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (auto nxt: {cur * 2, cur + 1, cur - 1}) {
            if (nxt < 0 || nxt >= SIZE || v[nxt]) continue;
            v[nxt] = v[cur] + 1;
            q.push(nxt);
        }
    }
    cout << v[k] - 1;
    return 0;
}

