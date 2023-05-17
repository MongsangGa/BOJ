#include<bits/stdc++.h>

using namespace std;

int n, a;
vector<int> v[101];
bool check[101];

void solve(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (!check[v[x][i]]) {
            check[v[x][i]] = 1;
            solve(v[x][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a) v[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        fill(check, check + 101, 0);
        solve(i);
        for (int j = 0; j < n; j++)
            cout << check[j] << ' ';
        cout << '\n';
    }
    return 0;
}
