#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 102
struct a {
    int x, y, Max, Min;
};
int n, res = 1e9, arr[SIZE][SIZE], vis[SIZE][SIZE][SIZE * 2], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<a> q;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    fill(&vis[0][0][0], &vis[SIZE - 1][SIZE - 1][SIZE * 2 - 1], 1e9);
    vis[0][0][arr[0][0]] = arr[0][0];
    q.push({0, 0,
            arr[0][0], arr[0][0]});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.x == n - 1 && cur.y == n - 1) {
            res = min(res, cur.Max - cur.Min);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            int nMax = max(cur.Max, arr[nx][ny]), nMin = min(cur.Min, arr[nx][ny]);
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny][nMin] <= nMax) continue;
            q.push({nx, ny,
                    nMax, nMin});
            vis[nx][ny][nMin] = nMax;
        }
    }
    cout << res;
    return 0;
}
