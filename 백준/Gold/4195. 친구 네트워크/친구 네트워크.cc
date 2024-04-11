#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 200'002

int t, n, p[SIZE], arr[SIZE];
map<string, int> m;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    p[b] = a;
    arr[a] += arr[b];
    arr[b] = 0;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt = 0;
        string a, b;
        m.clear();
        for (int i = 0; i <= n * 2 + 1; i++) p[i] = i, arr[i] = 1;
        while (n--) {
            cin >> a >> b;
            if (!m[a]) m[a] = ++cnt;
            if (!m[b]) m[b] = ++cnt;
            merge(m[b], m[a]);
            cout << max(arr[find(m[a])], arr[find(m[b])]) << '\n';
        }
    }
    return 0;
}
