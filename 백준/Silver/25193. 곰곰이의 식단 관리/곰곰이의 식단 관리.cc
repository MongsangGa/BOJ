#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, chicken, other;
string s;

int main() {
    fastio;
    cin >> n >> s;
    for (auto c: s) {
        if (c == 'C') ++chicken;
        else ++other;
    }
    cout << ceil((float) chicken / (float) (other + 1));
    return 0;
}
