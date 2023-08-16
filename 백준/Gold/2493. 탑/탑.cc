#include <bits/stdc++.h>

using namespace std;

int n, a;
stack<pair<int, int>> st; // cost, idx

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    st.push({0, 0});
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!st.empty() && st.top().first < a) {
            st.pop();
        }
        if (st.empty()) cout << "0 ";
        else cout << st.top().second + 1 << ' ';
        st.push({a, i});
    }
}
