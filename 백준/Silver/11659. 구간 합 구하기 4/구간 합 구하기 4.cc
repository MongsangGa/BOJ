#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE (int)1e6 + 2

int n, m, arr[SIZE], psum[SIZE];

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    psum[0] = arr[0];
    for (int i = 1; i < n; i++)
        psum[i] = psum[i - 1] + arr[i];
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << psum[b - 1] - psum[a - 2] << '\n';
    }
    return 0;
}
