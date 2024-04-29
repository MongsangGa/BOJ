#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define SIZE 52
#define INF 1e9

/*
 * top 0
 * right 1
 * bottom 2
 * left 3
 */
struct A {
    int x, y, dir, time;
};

pii Mirror(int dir) {
    if (dir % 2) return {0, 2};
    else return {1, 3};
}

char arr[SIZE][SIZE];
int n, res = INF, vis[SIZE][SIZE][4], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
queue<A> q;

int main() {
    fastio;
    pii st;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
                st = {i, j};
        }
    }
    fill(&vis[0][0][0], &vis[SIZE - 1][SIZE - 1][3], INF);
    for (int i = 0; i < 4; i++)
        q.push({st.first, st.second, i, 0});
    arr[st.first][st.second] = '*';
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (vis[cur.x][cur.y][cur.dir] <= cur.time) continue;
        vis[cur.x][cur.y][cur.dir] = cur.time;
        int nx = cur.x + dx[cur.dir], ny = cur.y + dy[cur.dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == '*') continue;
        if (arr[nx][ny] == '#')
            res = min(res, cur.time);
        else if (arr[nx][ny] == '.')
            q.push({nx, ny, cur.dir, cur.time});
        else if (arr[nx][ny] == '!') {
            q.push({nx, ny, cur.dir, cur.time});
            pii mirror = Mirror(cur.dir);
            q.push({nx, ny, mirror.first, cur.time + 1});
            q.push({nx, ny, mirror.second, cur.time + 1});
        }
    }
    cout << res;
    return 0;
}
