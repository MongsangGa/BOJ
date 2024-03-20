#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
const int ROOT = 1;
const int SIZE = 10'002;
const int MAX = SIZE * 500;

int n, m, unused = 2, nxt[MAX][26], res;
bool chk[MAX];

int INDEX(char c) { return c - 'a'; }

void INSERT(string &s) {
    int now = ROOT;
    for (auto c: s) {
        if (nxt[now][INDEX(c)] == -1)
            nxt[now][INDEX(c)] = unused++;
        now = nxt[now][INDEX(c)];
    }
    chk[now] = 1;
}

bool FIND(string &s) {
    int now = ROOT;
    for (auto c: s) {
        if (nxt[now][INDEX(c)] == -1)
            return 0;
        now = nxt[now][INDEX(c)];
    }
    return chk[now];
}

int main() {
    fastio;
    for (int i = 0; i < MAX; i++) fill(nxt[i], nxt[i] + 26, -1);
    cin >> n >> m;
    string s;
    while (n--) {
        cin >> s;
        INSERT(s);
    }
    while (m--) {
        cin >> s;
        res += FIND(s);
    }
    cout << res;
    return 0;
}
