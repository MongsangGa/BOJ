#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define P pair<int,int>
#define T tuple<long long int,int,int>
#define SIZE 1001

int t, n, m, student[SIZE], book[SIZE];
vector<int> adj[SIZE];
bool chk[SIZE];

bool DFS(int from) {
    chk[from] = 1;
    for (auto to: adj[from]) {
        if (book[to] == -1 || (!chk[book[to]] && DFS(book[to]))) {
            student[from] = to, book[to] = from;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < SIZE; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            for (int j = a; j <= b; j++)
                adj[i].push_back(j);
        }
        fill(student, student + SIZE, -1);
        fill(book, book + SIZE, -1);
        int res = 0;
        for (int i = 1; i <= m; i++) {
            if (student[i] == -1) {
                fill(chk, chk + SIZE, 0);
                if (DFS(i)) res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
