#include<bits/stdc++.h>

using namespace std;

int n, a, b, c, d, now = 301, idx, MAX = -1, res;
vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        v[i] = {a * 100 + b, c * 100 + d};
    }
    sort(v.begin(), v.end());
    while (now <= 1130) {
        for (int i = idx; i < n; i++) {
            auto &[s, e] = v[i];
            if (s > now) break;
            MAX = max(MAX, e);
            idx = i;
        }
        if (now == MAX) {
            cout << "0";
            exit(0);
        }
        now = MAX, res++;
    }
    cout << res;
    return 0;
}
