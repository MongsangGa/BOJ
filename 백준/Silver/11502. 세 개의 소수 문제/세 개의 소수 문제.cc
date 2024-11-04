#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int t, n;
bool isPrime[1002];
vector<int> v;

int main() {
    fastio;
    cin >> t;
    fill(isPrime, isPrime + 1002, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1000; i++)
        if (isPrime[i])
            for (int j = i * i; j <= 1000; j += i)
                isPrime[j] = 0;
    for (int i = 2; i <= 1000; i++)
        if (isPrime[i])
            v.push_back(i);
    while (t--) {
        cin >> n;
        bool flag = 0;
        for (auto i: v) {
            for (auto j: v) {
                if (i + j >= n) continue;
                if (isPrime[n - (i + j)]) {
                    cout << i << ' ' << j << ' ' << n - (i + j) << '\n';
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) cout << "0\n";
    }
    return 0;
}
// 2 3 5 7 11 13 15 17 19 23
