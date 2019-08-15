#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> seq;
int main() {
	int n, m;
	cin >> n >> m;
	seq.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i < n; i++) {
		int left = i + 1, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (seq[mid] + seq[i] == m) {
				printf("%d %d", seq[i], seq[mid]);
				return 0;
			}
			if (seq[mid] + seq[i] > m) {
				right = mid - 1;
			}
			if (seq[mid] + seq[i] < m) {
				left = mid + 1;
			}
		}
	}
	printf("No Solution");
	return 0;
}