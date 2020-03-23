#include<iostream>
using namespace std;
void swap(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int main() {
	int n, index, count = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &index);
		a[index] = i;
	}
	for (int i = 1; i < n; i++) {
		while (a[0] != 0) {
			swap(a, 0, a[0]);
			count++;
		}
		if (a[i] != i) {
			swap(a, 0, i);
			count++;
		}
	}
	cout << count;
	return 0;
}