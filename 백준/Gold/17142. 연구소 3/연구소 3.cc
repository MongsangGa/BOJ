#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAX 51

int n, m, arr[MAX][MAX], res = 1e9, blank, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
bool chk;
vector<pii> virus;

void BFS(vector<pii> v) {
    int temp[MAX][MAX], cnt = blank, time = 0;
    queue<pii> q;
    memcpy(temp, arr, sizeof(arr));
    for (auto &i: v) {
        q.push(i);
        temp[i.first][i.second] = 3; // visit is 3
    }
    while (!q.empty()) {
        if (!cnt) {
            chk = true;
            res = min(res, time);
            break;
        }
        time++;
        int len = q.size();
        while (len--) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (temp[nx][ny] == 1 || temp[nx][ny] == 3) continue;
                if (!temp[nx][ny]) cnt--;
                temp[nx][ny] = 3;
                q.push({nx, ny});
            }
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (!arr[i][j]) blank++;
            else if (arr[i][j] == 2) virus.push_back({i, j});
        }
    }
    vector<int> able_virus(virus.size(), 0);
    for (int i = 0; i < m; i++) able_virus[i] = 1;
    std::sort(able_virus.begin(), able_virus.end());
    do {
        vector<pii> v;
        for (int i = 0; i < able_virus.size(); i++)
            if (able_virus[i])
                v.push_back({virus[i].first, virus[i].second});
        BFS(v);
    } while (next_permutation(able_virus.begin(), able_virus.end()));
    if (!chk) cout << "-1";
    else cout << res;
    return 0;
}
