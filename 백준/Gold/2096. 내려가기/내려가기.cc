#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int n, a, b, c;
vector<int> minDp(3), maxDp(3);

int main() {
    fastio
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (!i)
            minDp[0] = maxDp[0] = a, minDp[1] = maxDp[1] = b, minDp[2] = maxDp[2] = c;
        else {
            vector<int> tMin = minDp, tMax = maxDp;
            minDp[0] = min(tMin[0], tMin[1]) + a;
            minDp[1] = min(min(tMin[0], tMin[1]), tMin[2]) + b;
            minDp[2] = min(tMin[1], tMin[2]) + c;

            maxDp[0] = max(tMax[0], tMax[1]) + a;
            maxDp[1] = max(max(tMax[0], tMax[1]), tMax[2]) + b;
            maxDp[2] = max(tMax[1], tMax[2]) + c;
        }
    }
    cout << *max_element(maxDp.begin(), maxDp.end()) << ' ' << *min_element(minDp.begin(), minDp.end());
    return 0;
}
