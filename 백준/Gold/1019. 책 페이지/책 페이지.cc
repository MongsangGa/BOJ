#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 100'001

int n;
long long int res[10];

void Calc(int cur, int len) {
    while (cur) {
        res[cur % 10] += len;
        cur /= 10;
    }
}

void solve(int a, int b, int len) {
    while (a % 10 && a <= b) {
        Calc(a, len);
        a++;
    }
    if (a > b) return;
    while (b % 10 != 9 && a <= b) {
        Calc(b, len);
        b--;
    }
    long long int temp = b / 10 - a / 10 + 1;
    for (int i = 0; i < 10; i++)
        res[i] += temp * len;
    solve(a / 10, b / 10, len * 10);
}

int main() {
    fastio;
    cin >> n;
    solve(1, n, 1);
    for (int i = 0; i < 10; i++) cout << res[i] << ' ';
    return 0;
}

