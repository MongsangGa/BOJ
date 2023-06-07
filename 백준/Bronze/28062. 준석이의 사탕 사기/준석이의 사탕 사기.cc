#include<bits/stdc++.h>

using namespace std;

int n, Modd = 1001, a, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        if (a & 1)
            Modd = min(Modd, a);
    }
    if (sum & 1) cout << sum - Modd;
    else cout << sum;
    return 0;
}
