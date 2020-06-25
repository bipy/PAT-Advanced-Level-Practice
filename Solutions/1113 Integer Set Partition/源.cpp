#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> seq;
int main() {
	int N, temp;
	cin >> N;
	seq.resize(N, 0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}
	sort(seq.begin(), seq.end());
	for (int i = 1; i < N; i++) {
		seq[i] = seq[i - 1] + seq[i];
	}
	if (N % 2 == 0) {
		int mid = N / 2 - 1;
		int ans = abs(seq[N - 1] - 2*seq[mid]);
		printf("0 %d", ans);
	}
	else {
		int mid = N / 2;
		int ans = max(abs(seq[N - 1] - 2 * seq[mid - 1]), abs(seq[N - 1] - 2 * seq[mid + 1]));
		printf("1 %d", ans);
	}
	return 0;
}