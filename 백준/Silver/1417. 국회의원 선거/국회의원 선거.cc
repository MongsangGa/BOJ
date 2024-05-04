#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, x, target, temp;
priority_queue<int> q;

int main() {
    fastio;
    cin >> n >> target;
    temp = target;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        q.push(x);
    }
    while (!q.empty() && q.top() >= target) {
        x = q.top();
        q.pop();
        target++;
        q.push(x - 1);
    }
    cout << target - temp;
    return 0;
}
