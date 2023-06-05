#include<bits/stdc++.h>

using namespace std;

long long int n, l, r, res = 3e9, arr[3], sum;
vector<long long int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 2; i++) {
        l = i + 1, r = n - 1;
        while (l < r) {
            sum = v[i] + v[l] + v[r];
            if (abs(res) > abs(sum))
                res = sum, arr[0] = v[i], arr[1] = v[l], arr[2] = v[r];
            if (sum >= 0) r--;
            else l++;
        }
    }
    sort(arr, arr + 3);
    for (int i = 0; i < 3; i++) cout << arr[i] << ' ';
    return 0;
}
