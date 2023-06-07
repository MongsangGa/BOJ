#include <bits/stdc++.h>
using namespace std;

int n, m, pos;
vector<int> a;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) a.push_back(i + 1);
	printf("<");
	while (1) {
		pos = (pos + m - 1) % a.size();
		if (a.size() > 1) {
			printf("%d, ", a[pos]);
		}
		else {
			printf("%d>", a[pos]);
			break;
		}
		a.erase(a.begin() + pos);
	}
	return 0;
}