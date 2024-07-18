#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define INF 1e9
#define SIZE 2222

int n, dp[SIZE][SIZE];

int f(int board, int screen) {
    if (board > 2 * n || screen > 2 * n || screen < 0) return INF;
    if (screen == n) return 0;

    int &res = dp[board][screen];
    if (res != -1) return res;
    res = INF;
    res = min(res, f(screen, screen) + 1);
    res = min(res, f(board, screen + board) + 1);
    res = min(res, f(board, screen - 1) + 1);
    return res;
}

int main() {
    fastio;
    cin >> n;
    fill(dp[0], dp[SIZE - 1], -1);
    cout << f(0, 1);
    return 0;
}
