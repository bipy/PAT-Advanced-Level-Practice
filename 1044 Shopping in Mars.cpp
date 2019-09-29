#include<iostream>
#include<vector>
using namespace std;
int n, m, minv = INT32_MAX;
bool eq = false;
vector<int> dia;
void process(int m) {
	for (int i = 0; i < n; i++) {
		int left = i, right = n - 1, mid, pre = i == 0 ? 0 : dia[i - 1];
		while (left <= right) {
			mid = (left + right) / 2;
			if (dia[mid] - pre == m) {
				printf("%d-%d\n", i + 1, mid + 1);
				eq = true;
				break;
			}
			if (dia[mid] - pre > m) {
				right = mid - 1;
			}
			else if (dia[mid] - pre < m) {
				left = mid + 1;
			}
		}
		if (!eq) {
			if (mid != n - 1 && dia[mid] - pre < m && dia[mid + 1] - pre < minv) {
				minv = dia[mid + 1] - dia[i - 1];
			}
			else if (dia[mid] - pre > m && dia[mid] - pre < minv) {
				minv = dia[mid] - pre;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	dia.resize(n);
	cin >> dia[0];
	for (int i = 1; i < n; i++) {
		cin >> dia[i];
		dia[i] += dia[i - 1];
	}
	process(m);
	if (!eq) {
		process(minv);
	}
	return 0;
}