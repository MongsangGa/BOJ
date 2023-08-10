#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int n, m, res;
string a[MAX], b[MAX];

void solve(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (a[i][j] == '0') a[i][j] = '1';
            else a[i][j] = '0';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                solve(i, j);
                res++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != b[i][j])
                res = -1;
    cout << res;
}
