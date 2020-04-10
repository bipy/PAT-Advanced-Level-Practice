#include<iostream>
#include<vector>
#include<algorithm>
#define Insertion 1
#define Merge 2
using namespace std;
int tag = 0;
vector<int> sample, I, M;
bool check(vector<int>& sample, vector<int>& test) {
	for (int i = 0; i < sample.size(); i++) {
		if (sample[i] != test[i]) {
			return false;
		}
	}
	return true;
}
void insertion() {
	bool flag = false;
	for (int i = 1; i < I.size(); i++) {
		int j = i - 1, k = I[i];
		while (j >= 0 && I[j] > k) {
			I[j + 1] = I[j];
			j--;
		}
		I[j + 1] = k;
		if (check(sample, I) && !flag) {
			tag = Insertion;
			flag = true;
		}
		else if (flag) {
			break;
		}
	}

}
void merge() {
	bool flag = false;
	for (int step = 1; step < 2 * M.size(); step *= 2) {
		int j = 0;
		while (j + step < M.size()) {
			sort(M.begin() + j, M.begin() + j + step);
			j += step;
		}
		sort(M.begin() + j, M.end());
		if (check(sample, M) && !flag) {
			tag = Merge;
			flag = true;
		}
		else if (flag) {
			break;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		I.push_back(temp);
		M.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		sample.push_back(temp);
	}
	insertion();
	if (tag == 0) {
		merge();
		printf("Merge Sort\n");
		for (int i = 0; i < M.size(); i++) {
			i == 0 ? printf("%d", M[i]) : printf(" %d", M[i]);
		}
	}
	else {
		printf("Insertion Sort\n");
		for (int i = 0; i < I.size(); i++) {
			i == 0 ? printf("%d", I[i]) : printf(" %d", I[i]);
		}
	}
	return 0;
}