#include<bits/stdc++.h>

using namespace std;

int n, m, a, root[201], input[1001];

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    root[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        root[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a)
                merge(i + 1, j + 1);
        }
    }
    for (int i = 0; i < m; i++)
        cin >> input[i];
    int res = find(input[0]);
    for (int i = 1; i < m; i++) {
        if (res != find(input[i])) {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    return 0;
}
