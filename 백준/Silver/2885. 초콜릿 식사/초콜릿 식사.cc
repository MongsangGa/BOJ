#include<bits/stdc++.h>

using namespace std;

int n, max_size = 1, res;

int main() {
    cin >> n;
    while (n > max_size)
        max_size *= 2;
    cout << max_size << ' ';
    while (n > 0) {
        while (max_size > n) {
            max_size /= 2;
            res++;
        }
        n -= max_size;
    }
    cout << res;
    return 0;
}
