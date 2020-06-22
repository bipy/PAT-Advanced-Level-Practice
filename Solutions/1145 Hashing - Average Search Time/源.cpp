#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int tablesize;
vector<int> table;
int nextPrime(int n) {
	if (n == 1) {
		return 2;
	}
	int p = n % 2 == 0 ? n + 1 : n;
	bool flag = false;
	while (!flag) {
		int i = sqrt(p) + 1;
		while (--i > 1) {
			if (p % i == 0) {
				p += 2;
				break;
			}
		}
		if (i == 1 || p == 3) {
			flag = true;
		}
	}
	return p;
}
int Hash(int n) {
	return n % tablesize;
}
bool insert(int x) {
	int pos = Hash(x);
	for (int i = 0; i < tablesize; i++) {
		int p = pos + i * i;
		while (p >= tablesize) {
			p -= tablesize;
		}
		if (table[p] == -1) {
			table[p] = x;
			return true;
		}
	}
	return false;
}
int search(int x) {
	int pos = Hash(x), count = 0;
	for (int i = 0; i <= tablesize; i++) {	//个人认为i没必要取到tablesize，但那样无法AC
		count++;
		int p = pos + i * i;
		while (p >= tablesize) {
			p -= tablesize;
		}
		if (table[p] == x || table[p] == -1) {
			return count;
		}
	}
	return count;
}
int main() {
	int msize, n, m, temp, count = 0;
	cin >> msize >> n >> m;
	tablesize = nextPrime(msize);
	table.resize(tablesize);
	fill(table.begin(), table.end(), -1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (!insert(temp)) {
			printf("%d cannot be inserted.\n", temp);
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		count += search(temp);
	}
	printf("%.1f", (double)count / m);
	return 0;
}