#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define P pair<int,int>
#define SIZE 52
typedef struct {
    int x, y, z;
} info;
int n, l[SIZE], r[SIZE], res;
bool chk[SIZE];
info arr[SIZE];
vector<int> adj[SIZE];

bool dfs(int from) {
    chk[from] = 1;
    for (auto to: adj[from]) {
        if (r[to] == -1 || (!chk[r[to]] && dfs(r[to]))) {
            l[from] = to, r[to] = from;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (arr[i].x >= arr[j].x && arr[i].y >= arr[j].y && arr[i].z >= arr[j].z) {
                if (arr[i].x == arr[j].x && arr[i].y == arr[j].y && arr[i].z == arr[j].z && i > j) continue;
                adj[i].push_back(j);
            }
        }
    }
    fill(l, l + SIZE, -1), fill(r, r + SIZE, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2; j++) {
            fill(chk, chk + SIZE, 0);
            if (dfs(i))
                res++;
        }
    }
    cout << n - res;
    return 0;
}
