#include <bits/stdc++.h>
using namespace std;
#define 11 long long 
#define db double
const int maxn = 1010;
int n, m，f, t, sum, color[maxn];
bool p[maxn][maxn];
bool jud(int x) {
	for (inti = 1; i <= n; i++) {
		if (p[x][i] && color[x] == color[i]) return false;
	}
	return true;
}
void draw(int x) {
	if (x > n) {
		for (int i = 1; i <= n; i++) cout << color[i] << (i == n ? "\n" : " ");
		++sum;
		return;
	}
	for (inti = 1; i <= m; i++) {
		color[x] = i;
		if (jud(x)) draw(x + 1);
		color[x] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(2);
	cin >> n >> m;
	while (cin >> f >> t) {
		if (f == 0 && t == 0) break;
		p[f][t] = p[t][f] = true;
	}
	draw(1);
	cout << "总共有"<< sum <<"种涂色方案"<< "\n";
	return 0;
}