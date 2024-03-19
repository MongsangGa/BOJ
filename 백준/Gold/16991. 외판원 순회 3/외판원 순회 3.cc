#include <bits/stdc++.h>

using namespace std;

#define SIZE 17
#define INF 1e9

int n;
pair<int, int> arr[SIZE];
double adj[SIZE][SIZE], dp[SIZE][1 << SIZE];

double solve(int now, int vis) {
    if (vis == (1 << n) - 1) {
        if (adj[now][0]) return adj[now][0];
        return INF;
    }
    double &res = dp[now][vis];
    if (res != 0) return res;
    res = INF;
    for (int nxt = 0; nxt < n; nxt++)
        if (!(vis & 1 << nxt) && adj[now][nxt])
            res = min(res, solve(nxt, vis | 1 << nxt) + adj[now][nxt]);
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    for (int now = 0; now < n; now++) {
        for (int nxt = 0; nxt < n; nxt++) {
            if (now == nxt) continue;
            adj[now][nxt] = sqrt(pow(arr[now].first - arr[nxt].first, 2) + pow(arr[now].second - arr[nxt].second, 2));
        }
    }
    printf("%.6lf", solve(0, 1));
    return 0;
}
