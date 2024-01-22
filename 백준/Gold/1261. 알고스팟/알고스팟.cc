#include <bits/stdc++.h>

using namespace std;

#define T tuple<int,int,int>
#define INF 1e9
#define SIZE 102
int n, m, d[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char arr[SIZE][SIZE];
priority_queue<T, vector<T >, greater<>> pq; // cost, x, y

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    fill(d[0], d[SIZE - 1], INF);
    d[1][1] = 0;
    pq.push({d[1][1], 1, 1});
    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();
        if (x == n && y == m) break;
        if (d[x][y] != cost) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (arr[nx][ny] == '1') {
                if (d[nx][ny] <= d[x][y] + 1) continue;
                d[nx][ny] = d[x][y] + 1;
                pq.push({d[x][y] + 1, nx, ny});
            } else {
                if (d[nx][ny] <= d[x][y]) continue;
                d[nx][ny] = d[x][y];
                pq.push({d[x][y], nx, ny});
            }
        }
    }
    cout << d[n][m];
    return 0;
}
