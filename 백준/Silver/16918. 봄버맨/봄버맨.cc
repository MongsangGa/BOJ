#include<bits/stdc++.h>

using namespace std;

#define SIZE 202
int n, m, k, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char arr[SIZE][SIZE];
queue<pair<int, int>> q;

void solve() {
    if (!(k % 2)) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = 'O';
    } else {
        int cur = 1;
        while (cur < k) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == 'O')
                        q.push({i, j});
                    arr[i][j] = 'O';
                }
            }

            while (!q.empty()) {
                int x, y;
                tie(x, y) = q.front();
                q.pop();
                arr[x][y] = '.';
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    arr[nx][ny] = '.';
                }
            }
            cur += 2;
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    solve();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j];
        cout << '\n';
    }
    return 0;
}
