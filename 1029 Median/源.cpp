#include<iostream>
#define maxN 200002
#define INF 0x7fffffff
using namespace std;
int main() {
	int temp, n, m, seq[maxN], count = 0;
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		scanf("%d", &seq[j]);
	}
	seq[n] = INF;
	scanf("%d", &m);
	int midpos = (n + m + 1) / 2, i = 0;
	for (int j = 0; j < m; j++) {
		scanf("%d", &temp);
		while (seq[i] < temp) {
			count++;
			if (count == midpos) {
				printf("%d", seq[i]);
			}
			i++;
		}
		count++;
		if (count == midpos) {
			printf("%d", temp);
		}
	}
	while (i < n) {
		count++;
		if (count == midpos) {
			printf("%d", seq[i]);
		}
		i++;
	}
	return 0;
}