#include<bits/stdc++.h>

using namespace std;

#define MAX 100001
int root[MAX], gate, plane, n, res;

int find(int x) {
    if (root[x] == x) return x;
    else return root[x] = find(root[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> gate >> plane;
    for (int i = 0; i <= gate; i++) root[i] = i;
    for (int i = 0; i < plane; i++) {
        cin >> n;
        int v = find(n);
        if (!v) break;
        res++, root[v] = v - 1;
    }
    cout << res;
    return 0;
}
/*
 * 4
 * 2
 * 2
 * 4
 */
