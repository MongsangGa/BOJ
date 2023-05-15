#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define MAX 1000001

ll arr[MAX], stree[MAX * 4], lazy[MAX * 4];
ll n, m, k, a, b, c, d;

ll init_stree(int node, int start, int end) {
    if (start == end) return stree[node] = arr[start];
    int mid = (start + end) / 2;
    return stree[node] = init_stree(node * 2, start, mid) + init_stree(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node]) {
        stree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll get_sum(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return stree[node];
    int mid = (start + end) / 2;
    return get_sum(node * 2, start, mid, left, right) + get_sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int left, int right, ll diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && right >= end) {
        stree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, diff);
    update(node * 2 + 1, mid + 1, end, left, right, diff);
    stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init_stree(1, 1, n);
    for (int i = 0; i < m + k; i++) {
        cin >> a;
        if (a == 1) { // b ~ c + d
            cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
        } else if (a == 2) {
            cin >> b >> c;
            cout << get_sum(1, 1, n, b, c) << '\n';
        }
    }
    return 0;
}