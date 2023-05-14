#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define MAX 100001
ll arr[MAX], stree[MAX * 4];
ll n, m, a, b, x, y;

ll init_tree(int node, int start, int end) {
    if (start == end) return stree[node] = arr[start];
    int mid = (start + end) / 2;
    return stree[node] = init_tree(node * 2, start, mid) + init_tree(node * 2 + 1, mid + 1, end);
}

ll get_sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return stree[node];
    int mid = (start + end) / 2;
    return get_sum(node * 2, start, mid, left, right) + get_sum(node * 2 + 1, mid + 1, end, left, right);
}

ll update(int node, int start, int end, int index, ll value) {
    if (index < start || index > end) return stree[node];
    if (start == end) return stree[node] = value;
    int mid = (start + end) / 2;
    return stree[node] = update(node * 2, start, mid, index, value) + update(node * 2 + 1, mid + 1, end, index, value);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init_tree(1, 1, n);
    while (m--) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << get_sum(1, 1, n, x, y) << '\n';
        update(1, 1, n, a, b);
    }
    return 0;
}