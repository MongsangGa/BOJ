#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 100'1

int n, d[SIZE];

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j < i; j++)
            d[i] = min(d[i], d[j] + d[i - j]);
    cout << d[n];
    return 0;
}
