#include<bits/stdc++.h>

using namespace std;

#define MAX 1000001

int n, m, order, a, b, root[MAX];

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
    for (int i = 0; i <= n; i++) root[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> order >> a >> b;
        if (!order) merge(a, b);
        else {
            int va = find(a);
            int vb = find(b);
            if (va == vb) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
