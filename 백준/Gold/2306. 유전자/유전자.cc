#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int dp[502][502];
string s;

int solve(int l, int r) {
    if (l >= r) return 0;
    int &now = dp[l][r];
    if (now != -1) return now;
    now = -1e9;
    for (int i = l; i < r; i++)
        now = max(now, solve(l, i) + solve(i + 1, r));
    if ((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c'))
        now = max(now, solve(l + 1, r - 1) + 2);
    return now;
}

int main() {
    fastio;
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << solve(0, s.size());
    return 0;
}
