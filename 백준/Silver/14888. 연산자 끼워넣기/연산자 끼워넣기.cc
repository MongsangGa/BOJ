#include <bits/stdc++.h>

using namespace std;

int n, arr[12], add, mina, multiple, divide, MAX = -1e9 - 1, MIN = 1e9 + 1;

void solve(int idx, int sum, int add, int mina, int multiple, int divide) {
    if (idx >= n) {
        MAX = max(sum, MAX);
        MIN = min(sum, MIN);
        return;
    }
    if (add) solve(idx + 1, sum + arr[idx], add - 1, mina, multiple, divide);
    if (mina) solve(idx + 1, sum - arr[idx], add, mina - 1, multiple, divide);
    if (multiple) solve(idx + 1, sum * arr[idx], add, mina, multiple - 1, divide);
    if (divide) solve(idx + 1, sum / arr[idx], add, mina, multiple, divide - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> add >> mina >> multiple >> divide;
    solve(1, arr[0], add, mina, multiple, divide);
    cout << MAX << '\n' << MIN;
}
