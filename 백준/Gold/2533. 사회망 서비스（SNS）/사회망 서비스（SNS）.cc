#include<bits/stdc++.h>

using namespace std;

#define MAX 1000001

int n, a, b, dp[2][MAX];
vector<int> arr[MAX];
bool check[MAX];

void solve(int now) {
    check[now] = 1;
    dp[0][now] = 1;
    // 노드가 일반인일때 1 = 자식들은 얼리어답터
    // 노드가 얼리어답터일때 0 = 자식들의 최소값
    int len = arr[now].size();
    for (int i = 0; i < len; i++) {
        int next = arr[now][i];
        if (check[next]) continue;
        solve(next);
        dp[0][now] += min(dp[0][next], dp[1][next]);
        dp[1][now] += dp[0][next];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    solve(1); // 1st node start
    cout << min(dp[0][1], dp[1][1]);
    return 0;
}
