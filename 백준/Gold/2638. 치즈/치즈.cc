#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 103

int n, m, arr[S][S];
bool vis[S][S];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
queue<pair<int, int>> cheese, air; // Cheese

void air_BFS() {
    fill(vis[0], vis[S], 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if ((!i || !j) && !arr[i][j])
                air.push({i, j});
        }
    while (!air.empty()) {
        auto [x, y] = air.front();
        air.pop();
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] || vis[nx][ny]) continue;
            air.push({nx, ny}), vis[nx][ny] = 1;
        }
    }
}

int cheese_BFS() {
    int res = 0;
    while (!cheese.empty()) {
        air_BFS();
        ++res;
        int qs = cheese.size();
        vector<pair<int, int>> delete_cheese;
        for (int k = 0; k < qs; k++) {
            auto [x, y] = cheese.front();
            cheese.pop();
            int chk = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] || !vis[nx][ny]) continue;
                ++chk;
            }
            if (chk >= 2) delete_cheese.push_back({x, y});
            else cheese.push({x, y});
        }
        for (auto [dx, dy]: delete_cheese)
            arr[dx][dy] = 0;
    }
    return res;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j])
                cheese.push({i, j});
        }
    cout << cheese_BFS();
    return 0;
}
