#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 200'002

int n, l, r, res, arr[SIZE], fruit[10];

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (r < n) {
        fruit[arr[r++]]++;
        while (count(fruit, fruit + 10, 0) < 8)
            fruit[arr[l++]]--;
        res = max(res, r - l);
    }
    cout << res;
    return 0;
}

