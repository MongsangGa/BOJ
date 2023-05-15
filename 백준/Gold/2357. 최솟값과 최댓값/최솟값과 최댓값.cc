#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define MAX 100001

ll arr[MAX], mintree[MAX * 4], maxtree[MAX * 4];
ll n, m, a, b;

ll init_min_tree(int node, int start, int end) {
    if (start == end) return mintree[node] = arr[start];
    int mid = (start + end) / 2;
    return mintree[node] = min(init_min_tree(node * 2, start, mid), init_min_tree(node * 2 + 1, mid + 1, end));
}

ll init_max_tree(int node, int start, int end) {
    if (start == end) return maxtree[node] = arr[start];
    int mid = (start + end) / 2;
    return maxtree[node] = max(init_max_tree(node * 2, start, mid), init_max_tree(node * 2 + 1, mid + 1, end));
}

ll get_max(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return maxtree[node];
    int mid = (start + end) / 2;
    return max(get_max(node * 2, start, mid, left, right), get_max(node * 2 + 1, mid + 1, end, left, right));
}

ll get_min(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1000000001;
    if (left <= start && right >= end) return mintree[node];
    int mid = (start + end) / 2;
    return min(get_min(node * 2, start, mid, left, right), get_min(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init_min_tree(1, 1, n);
    init_max_tree(1, 1, n);
    while (m--) {
        cin >> a >> b;
        cout << get_min(1, 1, n, a, b) << ' ' << get_max(1, 1, n, a, b) << '\n';
    }
    return 0;
}