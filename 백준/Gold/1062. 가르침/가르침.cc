#include <bits/stdc++.h>

using namespace std;

int n, k, bit[51], teach, t[] = {'a', 'n', 't', 'i', 'c'};
string s;

int dijkstra(int len, int idx) {
    int res = 0;
    if (len == (k - 5)) {
        for (int i = 0; i < n; i++)
            if ((teach & bit[i]) == bit[i])
                res++;
        return res;
    }
    for (int i = idx; i < 27; i++) {
        if (teach & (1 << i)) continue;
        teach |= (1 << i);
        res = max(res, dijkstra(len + 1, i + 1));
        teach &= ~(1 << i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (auto &c: s) bit[i] |= 1 << (c - 'a');
    }
    for (auto &c: t) teach |= 1 << (c - 'a');
    if (k < 5) cout << "0";
    else cout << dijkstra(0, 0);
    return 0;
}
