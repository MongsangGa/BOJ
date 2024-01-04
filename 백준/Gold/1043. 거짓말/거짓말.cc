#include <bits/stdc++.h>

using namespace std;

#define SIZE 52
int n, m, a, nt, root[SIZE], res;
vector<int> know, arr[SIZE];

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    root[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> nt;
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 0; i < nt; i++) {
        cin >> a;
        know.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> e;
            arr[i].push_back(e);
            if (!j) s = e;
            else {
                Union(s, e);
                s = e;
            }
        }
    }
    if (!nt) {
        cout << m;
        exit(0);
    }
    for (int i = 0; i < m; i++) {
        bool is = false;
        for (int j = 0; j < arr[i].size(); j++) {
            for (int k = 0; k < know.size(); k++) {
                if (find(arr[i][j]) == find(know[k])) {
                    is = true;
                    break;
                }
            }
            if (is) break;
        }
        if (!is) res++;
    }
    cout << res;
    return 0;
}
