#include<bits/stdc++.h>

using namespace std;

#define MAX 100001

int t, n, res;
int arr[MAX];
bool is_team[MAX], check[MAX];

void dfs(int n) {
    check[n] = true;
    int next = arr[n];
    if (!check[next])
        dfs(next);
    else if (!is_team[next]) {
        for (int i = next; i != n; i = arr[i])
            res++;
        res++;
    }
    is_team[n] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(is_team, 0, sizeof(is_team));
        memset(check, 0, sizeof(check));
        res = 0;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
            if (!check[i])
                dfs(i);
        cout << n - res << "\n";
    }
    return 0;
}
