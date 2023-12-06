#include<bits/stdc++.h>

using namespace std;

#define SIZE 1001
int t, n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, vis[SIZE][SIZE], fire[SIZE][SIZE];
char arr[SIZE][SIZE];
vector<pair<int, int>> f, v;
typedef pair<int, int> pii;

void Moving_fire() {
    queue<pii> q;
    for (int i = 0; i < f.size(); i++) q.push(f[i]);
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '#' || fire[nx][ny] != -1) continue;
            q.push({nx, ny});
            fire[nx][ny] = fire[x][y] + 1;
        }
    }
}

void Monvig_person() {
    queue<pii> q;
    q.push(v[0]);
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                cout << vis[x][y] + 1 << '\n';
                return;
            }
            if (vis[nx][ny] != -1 || arr[nx][ny] == '#' ||
                (fire[nx][ny] != -1 && fire[nx][ny] <= vis[x][y] + 1))
                continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> m >> n;
        fill(vis[0], vis[SIZE - 1], -1);
        fill(fire[0], fire[SIZE - 1], -1);
        f.clear(), v.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    v.push_back({i, j});
                    vis[i][j] = 0;
                } else if (arr[i][j] == '*') {
                    f.push_back({i, j});
                    fire[i][j] = 0;
                }
            }
        }
        Moving_fire();
        Monvig_person();
    }
    return 0;
}
