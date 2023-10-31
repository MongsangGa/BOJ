#include<bits/stdc++.h>

using namespace std;

long long int sum, now;
vector<pair<int, int>> v;
int n;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        now += v[i].second;
        if (now >= (sum + 1) / 2) {
            cout << v[i].first;
            break;
        }
    }
    return 0;
}