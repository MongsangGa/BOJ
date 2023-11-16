#include<bits/stdc++.h>

using namespace std;

string s, temp;
int score[4], i;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s;
    stringstream stream(s);
    while (getline(stream, temp, '/'))
        score[i++] = stoi(temp);
    if (score[0] + score[2] < score[1] || !score[1]) cout << "hasu";
    else cout << "gosu";
    return 0;
}
