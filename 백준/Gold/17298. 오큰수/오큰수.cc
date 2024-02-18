#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'000'001
int n, arr[SIZE];
stack<int> st;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            arr[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) arr[st.top()] = -1, st.pop();
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    return 0;
}
