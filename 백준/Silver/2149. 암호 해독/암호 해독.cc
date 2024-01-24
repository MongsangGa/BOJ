#include <bits/stdc++.h>

using namespace std;

string k, s;
vector<pair<char, int>> v;
int order[11];
char res[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for (int i = 0; i < k.size(); i++) v.push_back({k[i], i});
    sort(v.begin(), v.end());
    for (int i = 0; i < k.size(); i++)
        order[v[i].second] = i;
    cin >> s;
    int len1 = k.size(), len2 = s.size() / k.size();
    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            res[j][i] = s[i * len2 + j];
    for (int i = 0; i < len2; i++)
        for (int j = 0; j < len1; j++)
            cout << res[i][order[j]];
    return 0;
}