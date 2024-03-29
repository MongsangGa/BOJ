#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 103

int t, n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
bool key[30], vis[SIZE][SIZE];
char arr[SIZE][SIZE];
vector<tuple<char, int, int>> closed;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;

int BFS() {
    int ans = 0;
    q.push({0, 0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        auto [c, x, y] = q.top();
        q.pop();
        if (arr[x][y] >= 'A' && arr[x][y] <= 'Z' && !key[arr[x][y] - 'A']) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1 || vis[nx][ny] || arr[nx][ny] == '*') continue;
            if (arr[nx][ny] == '$' || arr[nx][ny] == '\0') {
                q.push({0, nx, ny});
                if (arr[nx][ny] == '$')
                    ++ans;
            } else if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
                q.push({1, nx, ny});
                key[arr[nx][ny] - 'a'] = true;
                for (auto [cc, cx, cy]: closed)
                    if (arr[nx][ny] - 'a' == cc - 'A')
                        q.push({2, cx, cy});
            } else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') {
                if (key[arr[nx][ny] - 'A']) q.push({2, nx, ny});
                else q.push({4, nx, ny}), closed.push_back({arr[nx][ny], nx, ny});
            } else if (arr[nx][ny] == '.') q.push({3, nx, ny});
            vis[nx][ny] = true;
        }
    }
    return ans;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        closed.clear();
        fill(key, key + 30, 0);
        fill(vis[0], vis[SIZE - 1], 0);
        fill(arr[0], arr[SIZE - 1], '\0');
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> arr[i][j];
        string s;
        cin >> s;
        for (auto i: s) if (isalpha(i)) key[i - 'a'] = true;
        int res = BFS();
        cout << res << '\n';
    }
    return 0;
}
