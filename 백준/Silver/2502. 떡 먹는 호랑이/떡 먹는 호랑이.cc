#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 33

int n, d, a[SIZE], b[SIZE];

int main() {
    fastio;
    cin >> n >> d;
    a[1] = 1, a[2] = 0;
    b[1] = 0, b[2] = 1;
    for (int i = 3; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2], b[i] = b[i - 1] + b[i - 2];
    for (int i = 1; i <= d; i++) {
        int x = d - (a[n] * i);
        if (x % b[n] == 0) {
            cout << i << '\n' << x / b[n];
            return 0;
        }
    }
    return 0;
}
