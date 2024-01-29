#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SIZE 201

int n, m, cow[SIZE], room[SIZE], res;
vector<int> adj[SIZE];
bool chk[SIZE];

bool DFS(int from) {
    chk[from] = 1;
    for (auto to: adj[from]) {
        if (room[to] == -1 || (!chk[room[to]] && DFS(room[to]))) {
            cow[from] = to, room[to] = from;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k, a;
        cin >> k;
        while (k--) {
            cin >> a;
            adj[i].push_back(a);
        }
    }
    fill(cow, cow + SIZE, -1);
    fill(room, room + SIZE, -1);
    for (int i = 1; i <= n; i++) {
        if (cow[i] == -1) {
            fill(chk, chk + SIZE, 0);
            if (DFS(i)) res++;
        }
    }
    cout << res;
    return 0;
}
