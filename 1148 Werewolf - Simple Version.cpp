#include<iostream>
#include<vector>
using namespace std;
vector<int> seq;
int main() {
	int n;
	cin >> n;
	seq.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &seq[i]);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bool flag = true;
			vector<bool> liar;
			for (int k = 1; k <= n; k++) {
				if (seq[k] < 0 && -seq[k] != i && -seq[k] != j) {
					if (k == i || k == j) {
						liar.push_back(true);
					}
					else {
						liar.push_back(false);
					}

				}
				else if (seq[k] > 0 && (seq[k] == i || seq[k] == j)) {
					if (k == i || k == j) {
						liar.push_back(true);
					}
					else {
						liar.push_back(false);
					}
				}
			}
			if (liar.size() == 2 && liar[0] != liar[1]) {
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}