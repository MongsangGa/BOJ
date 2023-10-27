#include<bits/stdc++.h>

using namespace std;
long long int n, b, c, res;

int main() {
    cin >> n;
    vector<long long int> exam(n);
    for (int i = 0; i < n; i++) cin >> exam[i];
    cin >> b >> c;
    for (int i = 0; i < n; i++) {
        int temp = 1;
        exam[i] -= b;
        if (exam[i] > 0) {
            temp += exam[i] / c;
            if (exam[i] % c) temp += 1;
        }
        res += temp;
    }
    cout << res;
    return 0;
}
