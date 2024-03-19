#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define SIZE 1002
int n, w, dp[SIZE][SIZE];
pii arr[SIZE];

int getDist(int x1, int x2) {
    pii a = arr[x1], b = arr[x2];
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int now, int l, int r) {
    if (now == w) return 0;
    int &res = dp[l][r];
    if (res) return res;
    int v1 = solve(now + 1, now + 1, r) + getDist(l, now + 1);
    int v2 = solve(now + 1, l, now + 1) + getDist(r, now + 1);
    res = min(v1, v2);
    return res;
}

void getPath(int now, int l, int r) {
    if (now == w) return;
    int v1 = solve(now + 1, now + 1, r) + getDist(l, now + 1);
    int v2 = solve(now + 1, l, now + 1) + getDist(r, now + 1);
    if (v1 < v2) {
        cout << "1\n";
        getPath(now + 1, now + 1, r);
    } else {
        cout << "2\n";
        getPath(now + 1, l, now + 1);
    }
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= w; i++)
        cin >> arr[i].first >> arr[i].second;
    arr[0] = {1, 1}, arr[w + 1] = {n, n};
    cout << solve(0, 0, w + 1) << '\n';
    getPath(0, 0, w + 1);
    return 0;
}
