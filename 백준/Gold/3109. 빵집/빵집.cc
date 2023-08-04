#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

int n, m, dx[] = {-1, 0, 1}, res;
bool chk[MAX][MAX];
string arr[MAX];

bool dfs(int x, int y) {
    if (y == m - 1) return true;
    for (int i = 0; i < 3; i++) {
        int X = x + dx[i], Y = y + 1;
        if (X < 0 || Y < 0 || X >= n || Y >= m || chk[X][Y] || arr[X][Y] == 'x') continue;
        chk[X][Y] = 1;
        if (dfs(X, Y))
            return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) // DFS
        res += dfs(i, 0);
    cout << res;
}

