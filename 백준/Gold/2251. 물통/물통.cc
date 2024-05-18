#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 202

struct A {
    int a, b, c;
};

int arr[3];
bool dp[SIZE][SIZE][SIZE];
queue<A> q;
vector<int> res;

int main() {
    fastio;
    for (int i = 0; i < 3; i++) cin >> arr[i];
    q.push({0, 0, arr[2]});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (dp[cur.a][cur.b][cur.c]) continue;
        dp[cur.a][cur.b][cur.c] = true;
        if (!cur.a) res.push_back(cur.c);
        // a -> b
        if (cur.a + cur.b > arr[1]) q.push({cur.a - (arr[1] - cur.b), arr[1], cur.c});
        else q.push({0, cur.a + cur.b, cur.c});
        // a -> c
        if (cur.a + cur.c > arr[2]) q.push({cur.a - (arr[2] - cur.c), cur.b, arr[2]});
        else q.push({0, cur.b, cur.a + cur.c});
        // b -> a
        if (cur.a + cur.b > arr[0]) q.push({arr[0], cur.b - (arr[0] - cur.a), cur.c});
        else q.push({cur.a + cur.b, 0, cur.c});
        // b -> c
        if (cur.b + cur.c > arr[2]) q.push({cur.a, cur.b - (arr[2] - cur.c), arr[2]});
        else q.push({cur.a, 0, cur.b + cur.c});
        // c -> a
        if (cur.a + cur.c > arr[0]) q.push({arr[0], cur.b, cur.c - (arr[0] - cur.a)});
        else q.push({cur.a + cur.c, cur.b, 0});
        // c -> b
        if (cur.b + cur.c > arr[1]) q.push({cur.a, arr[1], cur.c - (arr[1] - cur.b)});
        else q.push({cur.a, cur.b + cur.c, 0});
    }
    sort(res.begin(), res.end());
    for (auto i: res) cout << i << ' ';
    return 0;
}
