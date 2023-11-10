#include <bits/stdc++.h>

using namespace std;

int n, m, MAX, res[1001];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (n--) {
        int cnt = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            if (s[i - 1] != '1' && s[i] == '1')
                cnt++;
        MAX = max(MAX, cnt);
        res[cnt]++;
    }
    cout << MAX << ' ' << res[MAX];
    return 0;
}
