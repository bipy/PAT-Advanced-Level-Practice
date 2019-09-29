#include<iostream>
#define N 3	//the number of games
using namespace std;
int main() {
	double odd[3], profit = 1;
	char act[3] = { 'W','T','L' };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> odd[j];
		}
		int max = 0;
		for (int k = 1; k < 3; k++) {
			if (odd[max] < odd[k]) {
				max = k;
			}
		}
		profit *= odd[max];
		cout << act[max] << " ";
	}
	printf("%.2f", (profit * 0.65 - 1) * 2);
	return 0;
}