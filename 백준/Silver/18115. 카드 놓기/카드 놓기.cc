#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n;
vector<int> v;
deque<int> dq;

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 1; i <= n; i++) cin >> v[n - i];
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) dq.push_front(i + 1);
        else if (v[i] == 3) dq.push_back(i + 1);
        else dq.push_front(dq.front()), dq[1] = i + 1;
    }
    for (auto i: dq) cout << i << ' ';
    return 0;
}
