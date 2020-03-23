#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N, t;
	cin >> N;
	vector<int> seq;
	for (int i = 0; i < N; i++) {
		cin >> t;
		seq.push_back(t);
	}
	int max = -1, sum = 0, left = 0, right = N - 1, temp = 0;
	for (int i = 0; i < N; i++) {
		sum += seq[i];
		if (sum < 0) {
			sum = 0;
			temp = i + 1;
		}
		else if (sum > max) {
			max = sum;
			left = temp;
			right = i;
		}
	}
	if (max < 0) {
		max = 0;
	}
	printf("%d %d %d", max, seq[left], seq[right]);
	return 0;
}