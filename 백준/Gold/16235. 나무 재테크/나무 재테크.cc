#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ti tuple<int,int,int>
#define S 12

int n, m, k, A[S][S], P[S][S], dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> T[S][S];

void cycle() {
    // spring
    vector<ti > dT;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (T[i][j].empty()) continue;
            sort(T[i][j].begin(), T[i][j].end());
            vector<int> aT;
            for (int z: T[i][j]) {
                if (A[i][j] >= z) A[i][j] -= z, aT.push_back(z + 1);
                else dT.push_back({i, j, z});
            }
            T[i][j].clear();
            for (int z: aT) T[i][j].push_back(z);
        }
    }
    // summer
    for (auto [x, y, z]: dT) A[x][y] += floor((double) z / 2);
    // fall
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (T[i][j].empty()) continue;
            for (int z: T[i][j]) {
                if (z % 5) continue;
                for (int l = 0; l < 8; l++) {
                    int nx = i + dx[l], ny = j + dy[l];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    T[nx][ny].push_back(1);
                }
            }
        }
    }
    // winter
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) A[i][j] += P[i][j];
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> P[i][j];
    fill(A[0], A[S], 5);
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        T[x - 1][y - 1].push_back(z);
    }
    while (k--) {
        cycle();
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (T[i][j].empty()) continue;
            res += T[i][j].size();
        }
    cout << res;
    return 0;
}
