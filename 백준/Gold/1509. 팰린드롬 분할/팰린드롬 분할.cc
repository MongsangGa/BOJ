#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
#define S 2505

string s;
int res[S];
bool dp[S][S];

int main() {
    fastio;
    cin >> s;
    int n = s.size();
    for (int len = 1; len <= n; len++) {
        for (int st = 0; st <= n - len; st++) {
            if (len == 1) dp[st][st + len] = 1;
            else if (len == 2) dp[st][st + len] = (s[st] == s[st + 1]);
            else dp[st][st + len] = (s[st] == s[st + len - 1] && dp[st + 1][st + len - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        res[i] = 1e9;
        for (int j = 0; j < i; j++)
            if (dp[j][i]) res[i] = min(res[i], res[j] + 1);
    }
    cout << res[n];
    return 0;
}
