#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int N, temp;
	cin >> N;
	vector<double> seq(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		seq[i] = static_cast<double>(temp);
	}
	sort(seq.begin(), seq.end());
	seq[1] = (seq[0] + seq[1]) * 0.5;
	for (int i = 2; i < N; i++) {
		seq[i] = 0.5 * (seq[i - 1] + seq[i]);
	}
	cout << static_cast<int>(seq.back());
	return 0;
}