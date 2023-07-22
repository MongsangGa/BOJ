#include<bits/stdc++.h>

using namespace std;

#define MAX 500001

int n, m, a, b, va, vb, root[MAX];

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    if (x == y) return;
    root[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        root[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        va = find(a);
        vb = find(b);
        if (va == vb) {
            cout << i + 1;
            exit(0);
        }
        merge(va, vb);
    }
    cout << "0";
    return 0;
}
