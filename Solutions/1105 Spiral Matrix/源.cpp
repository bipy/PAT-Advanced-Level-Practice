#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
using namespace std;
vector<vector<int> > fmap;
vector<int> seq;
bool cmp(const int& a, const int& b) {
	return a > b;
}
void travel(int cur, int r, int c, int& m, int& n, int direction) {
	fmap[r][c] = seq[cur];
	if (direction == RIGHT) {
		if (c + 1 < n && fmap[r][c + 1] == -1) {
			travel(cur + 1, r, c + 1, m, n, direction);
		}
		else {
			direction = DOWN;
		}
	}
	if (direction == DOWN) {
		if (r + 1 < m && fmap[r + 1][c] == -1) {
			travel(cur + 1, r + 1, c, m, n, direction);
		}
		else {
			direction = LEFT;
		}
	}
	if (direction == LEFT) {
		if (c - 1 >= 0 && fmap[r][c - 1] == -1) {
			travel(cur + 1, r, c - 1, m, n, direction);
		}
		else {
			direction = UP;
		}
	}
	if (direction == UP) {
		if (r - 1 >= 0 && fmap[r - 1][c] == -1) {
			travel(cur + 1, r - 1, c, m, n, direction);
		}
		else if (c + 1 < n && fmap[r][c + 1] == -1) {
			travel(cur + 1, r, c + 1, m, n, RIGHT);
		}
	}
}
int main() {
	int N, m, n;
	cin >> N;
	for (int i = sqrt(N); i > 0; i--) {
		if (N % i == 0) {
			n = i;
			m = N / i;
			break;
		}
	}
	seq.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}
	sort(seq.begin(), seq.end(), cmp);
	fmap.resize(m, vector<int>(n, -1));
	travel(0, 0, 0, m, n, RIGHT);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			j == 0 ? printf("%d", fmap[i][j]) : printf(" %d", fmap[i][j]);
		}
		printf("\n");
	}
	return 0;
}