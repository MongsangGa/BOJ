#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, a, b, c, d[SIZE], kal, price;
double res;

int main() {
    fastio;
    cin >> n >> a >> b >> c;
    price = a, kal = c;
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n, greater<int>());
    res = kal / price;
    for (int i = 0; i < n; i++) {
        price += b, kal += d[i];
        if (res > kal / price) break;
        res = kal / price;
    }
    cout << floor(res);
    return 0;
}
