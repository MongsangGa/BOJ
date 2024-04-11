#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int main() {
    fastio;
    double a, b, c;
    cin >> a >> b >> c;
    cout << int(max(a * b / c, a / b * c));
    return 0;
}
