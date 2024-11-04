#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, k, arr[10'002];

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                --k;
            }
            if (!k) {
                for (int l = 0; l < n; l++)
                    cout << arr[l] << ' ';
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
