#include <bits/stdc++.h>

using namespace std;

int n, a, answer;
vector<int> v, res, Rres;

void LIS(vector<int> &arr) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (v[i] > v[j])
                arr[i] = max(arr[i], arr[j] + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    res.resize(n, 1);
    Rres.resize(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    LIS(res);
    reverse(v.begin(), v.end());
    LIS(Rres);
    reverse(Rres.begin(), Rres.end());
    for (int i = 0; i < n; i++)
        answer = max(answer, res[i] + Rres[i]);
    cout << answer - 1;
}
