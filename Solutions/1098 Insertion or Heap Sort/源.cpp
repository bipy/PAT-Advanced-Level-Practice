#include<iostream>
#include<vector>
#include<algorithm>
#define INSERTION 1
#define HEAP 2
using namespace std;
int tag = 0;
vector<int> sample, I, H;
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
			tag = INSERTION;
			flag = true;
		}
		else if (flag) {
			break;
		}
	}
}

void heap() {
	// 虽然知道此题考查Heap Sort的写法，但偷懒用STL了
	bool flag = false;
	make_heap(H.begin(), H.end());
	for (int rear = H.size() - 1; rear >= 0; rear--) {
		pop_heap(H.begin(), H.begin() + rear + 1);
		if (check(sample, H) && !flag) {
			tag = HEAP;
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
		H.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		sample.push_back(temp);
	}
	insertion();
	if (tag == 0) {
		heap();
		printf("Heap Sort\n");
		for (int i = 0; i < H.size(); i++) {
			i == 0 ? printf("%d", H[i]) : printf(" %d", H[i]);
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