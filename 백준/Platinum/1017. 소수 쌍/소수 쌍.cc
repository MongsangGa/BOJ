#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define P pair<int,int>
#define T tuple<long long int,int,int>
#define SIZE 200'2

int n, arr[SIZE], X[SIZE];
bool chk[SIZE], prime[SIZE];
vector<int> adj[SIZE];
vector<int> res;

bool dfs(int from) {
    chk[from] = true;
    for (auto to: adj[from]) {
        if (from == to || prime[arr[from] + arr[to]]) continue;
        if (X[to] == -1 || (!chk[X[to]] && dfs(X[to]))) {
            X[to] = from, X[from] = to;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    fill(prime, prime + SIZE, false);
    for (int i = 2; i < sqrt(SIZE); i++) {
        if (prime[i]) continue;
        for (int j = i * i; j < SIZE; j += i)
            prime[j] = true;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || prime[arr[i] + arr[j]]) continue;
            adj[i].push_back(j);
        }
    }
    for (auto i: adj[1]) {
        if (prime[arr[1] + arr[i]]) continue;
        int temp = 2;
        fill(X, X + SIZE, -1);
        X[1] = i, X[i] = 1;
        for (int j = 2; j <= n; j++) {
            if (X[j] == -1) {
                fill(chk, chk + SIZE, 0);
                chk[1] = chk[i] = true;
                if (dfs(j)) temp += 2;
            }
        }
        if (temp == n) res.push_back(arr[i]);
    }
    sort(res.begin(), res.end());
    if (res.empty()) cout << -1;
    else for (auto r: res) cout << r << ' ';
    return 0;
}
