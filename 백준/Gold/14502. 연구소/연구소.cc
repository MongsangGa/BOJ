#include <bits/stdc++.h>

using namespace std;

#define MAX 9

int n, m, arr[MAX][MAX], temp[MAX][MAX], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, res;
bool chk[MAX][MAX];
vector<pair<int, int>> virus, safe;
queue<pair<int, int>> q;

void solve() {
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        chk[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (chk[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (temp[nx][ny] != 1) {
                q.push({nx, ny});
                temp[nx][ny] = 2;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                virus.push_back({i, j});
            if (!arr[i][j])
                safe.push_back({i, j});
        }
    }
    vector<int> idx(safe.size(), 0);
    for (int i = 0; i < 3; i++) idx[i] = 1;
    sort(idx.begin(), idx.end());
    do {
        memcpy(temp, arr, sizeof(temp));
        memset(chk, 0, sizeof(chk));
        for (int i = 0; i < idx.size(); i++)
            if (idx[i])
                temp[safe[i].first][safe[i].second] = 1;
        for (int i = 0; i < virus.size(); i++)
            q.push({virus[i].first, virus[i].second});
        solve();
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!temp[i][j])
                    cnt++;
        res = max(res, cnt);
    } while (next_permutation(idx.begin(), idx.end()));
    cout << res;
    return 0;
}
