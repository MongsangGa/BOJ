#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 258

int t, aS, wS, sS, oi[SIZE], pi[SIZE], ans[65];
string a, w, s;
vector<int> res, f;

vector<int> failure() {
    vector<int> p(wS);
    int j = 0;
    for (int i = 1; i < wS; i++) {
        while (j > 0 && w[i] != w[j]) j = p[j - 1];
        if (w[i] == w[j]) p[i] = ++j;
    }
    return p;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> a >> w >> s;

        aS = a.size(), wS = w.size(), sS = s.size();
        vector<int>().swap(f);
        vector<int>().swap(res);
        fill(ans, ans + 65, 0);

        f = failure();
        for (int i = 0; i < aS; i++) oi[a[i]] = i;

        for (int k = 0; k < aS; k++) {
            for (int i = 0; i < aS; i++)
                pi[a[i]] = (oi[a[i]] + k) % aS;
            int j = 0;
            for (int i = 0; i < sS; i++) {
                while (j > 0 && oi[s[i]] != pi[w[j]]) j = f[j - 1];
                if (oi[s[i]] == pi[w[j]]) ++j;
                if (j == wS) {
                    j = f[j - 1]; // 계속 탐색
                    ans[k]++;
                }
            }
        }
        for (int i = 0; i < aS; i++)
            if (ans[i] == 1)
                res.push_back(i);
        if (!res.size()) cout << "no solution\n";
        else if (res.size() == 1) cout << "unique: " << res[0] << '\n';
        else {
            cout << "ambiguous: ";
            for (auto r: res) cout << r << ' ';
            cout << '\n';
        }
    }
    return 0;
}
