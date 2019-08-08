#include<iostream>
#define N 55
using namespace std;
int n, rule[55], pos[55], temp[55];
int main() {
	cin >> n;
	for (int i = 1; i < N; i++) {
		cin >> rule[i];
		pos[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int i = 1; i < N; i++) {
			temp[rule[i]] = pos[i];
		}
		for(int i=1;i<N;i++) {
			pos[i] = temp[i];
		}
	}
	char c[6] = { "SHCDJ" };
	for (int i = 1; i < N; i++) {
		i == N - 1 ? printf("%c%d", c[(pos[i] - 1) / 13], (pos[i] - 1) % 13 + 1) : printf("%c%d ", c[(pos[i] - 1) / 13], (pos[i] - 1) % 13 + 1);
	}
	return 0;
}