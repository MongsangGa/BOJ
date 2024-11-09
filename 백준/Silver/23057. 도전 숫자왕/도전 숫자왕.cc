#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define S 300'001

int n, sum;
set<int> s;

int main() {
    fastio;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                tmp += arr[i];
        s.insert(tmp);
    }
    cout << sum - s.size();
    return 0;
}
