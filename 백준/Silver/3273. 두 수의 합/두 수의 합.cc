#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 100'001

int n, x, arr[S], res;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    sort(arr, arr + n);
    int s = 0, e = n - 1;
    while (s < e) {
        if (arr[s] + arr[e] < x) s++;
        else if (arr[s] + arr[e] > x) e--;
        else res++, s++;
    }
    cout << res;
    return 0;
}
