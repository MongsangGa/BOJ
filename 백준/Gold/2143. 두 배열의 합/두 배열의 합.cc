#include<bits/stdc++.h>

using namespace std;

int t, n, m, a[1001], b[1001], sum;
long long int res;
vector<int> sumA, sumB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            sumA.push_back(sum);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < m; i++) {
        sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            sumB.push_back(sum);
        }
    }
    sort(sumB.begin(), sumB.end());
    for (int i = 0; i < sumA.size(); i++) {
        int findNum = t - sumA[i];
        auto up = upper_bound(sumB.begin(), sumB.end(), findNum);
        auto down = lower_bound(sumB.begin(), sumB.end(), findNum);
        res += up - down;
    }
    cout << res;
    return 0;
}
