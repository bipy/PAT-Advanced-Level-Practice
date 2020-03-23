#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int nextPrime(int x) {
	if (x <= 2) {
		return 2;
	}
	bool flag = false;
	int p = x % 2 ? x : x + 1;
	while (!flag) {
		int i = (int)sqrt(p) + 1;
		while (--i > 1) {
			if (p % i == 0) {
				p += 2;
				break;
			}
		}
		if (i == 1) {
			flag = true;
		}
	}
	return p;
}
int Hash(int x, int tsize) {
	return x % tsize;
}
int insert(vector<bool>& table, int x) {
	int tsize = table.size();
	int pos = Hash(x, tsize);
	for (int i = 0; i < tsize; i++) {
		int p = pos + i * i;
		while (p >= tsize) {
			p -= tsize;
		}
		if (!table[p]) {
			table[p] = true;
			return p;
		}
	}
	return -1;
}
int main() {
	int tsize, n;
	cin >> tsize >> n;
	tsize = nextPrime(tsize);
	vector<bool> table(tsize, false);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		int ans = insert(table, temp);
		if (i != 0) {
			printf(" ");
		}
		if (ans == -1) {
			printf("-");
		}
		else {
			printf("%d", ans);
		}
	}
	return 0;
}