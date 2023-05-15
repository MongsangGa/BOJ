#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define MAX 1000001
#define S 1000000007
ll arr[MAX], stree[MAX * 4];
ll n, m, k, a, b, c;

ll init_tree(int node, int start, int end) {
    if (start == end) return stree[node] = arr[start];
    int mid = (start + end) / 2;
    return stree[node] = (init_tree(node * 2, start, mid) * init_tree(node * 2 + 1, mid + 1, end)) % S;
}

ll get_multip(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && right >= end) return stree[node];
    int mid = (start + end) / 2;
    return (get_multip(node * 2, start, mid, left, right) * get_multip(node * 2 + 1, mid + 1, end, left, right)) % S;
}

ll update(int node, int start, int end, int index, ll value) {
    if (index < start || index > end) return stree[node];
    if (start == end) return stree[node] = value;
    int mid = (start + end) / 2;
    return stree[node] =
                   (update(node * 2, start, mid, index, value) * update(node * 2 + 1, mid + 1, end, index, value)) % S;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init_tree(1, 1, n);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 1, n, b, c);
        else if (a == 2)
            cout << get_multip(1, 1, n, b, c) << '\n';
    }
    return 0;
}