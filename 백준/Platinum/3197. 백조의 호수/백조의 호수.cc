#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define pii pair<int,int>
#define X first
#define Y second
#define SIZE 1505

char arr[SIZE][SIZE];
int n, m, vis[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pii > waterQ, swanQ;
vector<pii > swan;

void deleteIce() {
    int wS = waterQ.size();
    while (wS--) {
        auto [x, y] = waterQ.front();
        waterQ.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] != 'X') continue;
            waterQ.push({nx, ny}), arr[nx][ny] = '.';
        }
    }
}

bool meetSwan() {
    queue<pii > nSwan;
    while (!swanQ.empty()) {
        auto [x, y] = swanQ.front();
        swanQ.pop();
        if (x == swan[1].X && y == swan[1].Y) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            if (arr[nx][ny] == 'X') nSwan.push({nx, ny});
            else swanQ.push({nx, ny});
        }
    }
    swanQ = nSwan;
    return false;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'L') swan.push_back({i, j}), waterQ.push({i, j});
            if (arr[i][j] == '.') waterQ.push({i, j});
        }
    swanQ.push({swan[0].X, swan[0].Y});
    int t = 1;
    while (t) {
        if (meetSwan()) break;
        ++t;
        deleteIce();
    }
    cout << t - 1;
    return 0;
}

