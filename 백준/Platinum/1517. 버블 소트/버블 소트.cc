#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 500'001
#define ll long long int
ll n, a, res, stree[SIZE * 4];
vector<pair<int, int>> arr;

ll sum(int node, int s, int e, int findS, int findE) {
    if (s > findE || e < findS) return 0;
    if (findS <= s && e <= findE) return stree[node];
    int mid = (s + e) / 2;
    return sum(node * 2, s, mid, findS, findE) + sum(node * 2 + 1, mid + 1, e, findS, findE);
}

ll update(int node, int s, int e, int target) {
    if (s > target || e < target) return stree[node];
    if (s == e) return stree[node] = 1;
    int mid = (s + e) / 2;
    return stree[node] = update(node * 2, s, mid, target) + update(node * 2 + 1, mid + 1, e, target);
}

int main() {
    fastio
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back({a, i + 1});
    }
    sort(arr.begin(), arr.end());
    for (auto &[num, idx]: arr) {
        res += sum(1, 1, n, idx + 1, n);
        update(1, 1, n, idx);
    }
    cout << res;
    return 0;
}

/*
 * i < j && arr[i] > arr[j]
 * sort 를 하면 arr[i] < arr[j] 는 보장, 현재 수 idx 보다 뒤에 있는 것들의 수를 세면 된다
 */
