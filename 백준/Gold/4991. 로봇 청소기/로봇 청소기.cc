#include <bits/stdc++.h>

using namespace std;

#define SIZE 21
int n, m, pollute, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char arr[SIZE][SIZE], chk[1 << 10][SIZE][SIZE];

int BFS(pair<int, int> start) {
    int time = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, start.first, start.second});
    chk[0][start.first][start.second] = 1;
    while (!q.empty()) {
        int qs = q.size();
        for (int l = 0; l < qs; l++) {
            int bit, x, y;
            tie(bit, x, y) = q.front();
            q.pop();
            if (bit == (1 << pollute) - 1) return time;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 'x' || chk[bit][nx][ny]) continue;
                if (arr[nx][ny] >= 0 && arr[nx][ny] <= 9) {
                    q.push({(bit | (1 << arr[nx][ny])), nx, ny});
                    chk[bit | (1 << arr[nx][ny])][nx][ny] = 1;
                } else {
                    q.push({bit, nx, ny});
                    chk[bit][nx][ny] = 1;
                }
            }
        }
        time++;
    }
    return -1;
}

int main() {
    while (1) {
        cin >> m >> n;
        if (!n || !m) break;
        pair<int, int> start;
        pollute = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'o') start.first = i, start.second = j;
                if (arr[i][j] == '*') arr[i][j] = pollute++;
            }
        }
        cout << BFS(start) << '\n';
        memset(chk, 0, sizeof(chk));
    }
    return 0;
}
