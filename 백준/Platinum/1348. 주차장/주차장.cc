#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 102
#define MAX 2502

int n, m, ans = -1, X[SIZE], Y[SIZE], chk[SIZE], dis[SIZE][SIZE], vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1,
                                                                                                                 0,
                                                                                                                 1};
char board[SIZE][SIZE];
vector<pair<int, int>> C, P;
vector<int> adj[SIZE];
queue<pair<int, int>> q;

bool DFS(int from, int len) {
    chk[from] = 1;
    for (auto to: adj[from]) {
        if (dis[from][to] > len) continue;
        if (Y[to] == -1 || (!chk[Y[to]] && DFS(Y[to], len))) {
            X[from] = to, Y[to] = from;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'C') C.push_back({i, j});
            else if (board[i][j] == 'P') P.push_back({i, j});
        }
    }
    if (C.size() > P.size()) {
        cout << -1;
        exit(0);
    }
    // find Distance
    for (int i = 0; i < C.size(); i++) {
        fill(vis[0], vis[SIZE - 1], -1);
        auto [sX, sY] = C[i];
        q.push({sX, sY});
        vis[sX][sY] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board[nx][ny] == 'X' || vis[nx][ny] != -1) continue;
                vis[nx][ny] = vis[x][y] + 1;
                q.push({nx, ny});
            }
        }
        for (int j = 0; j < P.size(); j++) {
            if (vis[P[j].X][P[j].Y] == -1)
                dis[i][j] = MAX * MAX;
            else {
                adj[i].push_back(j);
                dis[i][j] = vis[P[j].X][P[j].Y];
            }
        }
    }
    // set Distance
    int st = 0, en = MAX;
    while (st <= en) {
        int mid = (st + en) / 2, res = 0;
        fill(X, X + SIZE, -1);
        fill(Y, Y + SIZE, -1);
        for (int i = 0; i < C.size(); i++) {
            if (X[i] != -1) continue;
            fill(chk, chk + SIZE, 0);
            if (DFS(i, mid))
                res++;
        }
        if (res == C.size()) ans = mid, en = mid - 1;
        else st = mid + 1;
    }
    cout << ans;
    return 0;
}
