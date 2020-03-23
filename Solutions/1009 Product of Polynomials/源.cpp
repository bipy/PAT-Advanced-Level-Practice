#include<iostream>
#define maxe 1001
using namespace std;
int main() {
	int K, e;
	double c;
	double p[maxe] = { 0.0 };
	double ans[maxe * 2] = { 0.0 };
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &e, &c);
		p[e] = c;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &e, &c);
		for (int j = 0; j < maxe; j++) {
			if (p[j] != 0) {
				ans[e + j] += p[j] * c;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 2 * maxe; i++) {
		if (ans[i] != 0) {
			count++;
		}
	}
	cout << count;
	for (int i = 2 * maxe - 1; i >= 0; i--) {
		if (ans[i] != 0) {
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}