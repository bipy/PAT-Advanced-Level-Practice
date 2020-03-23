#include<iostream>
#include<vector>
using namespace std;
vector<int> s, r;
int find(int key) {
	if(r.empty()) {
		return 0;
	}
	int left = 0, right = r.size() - 1, mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (r[mid] == key) {
			break;
		}
		if (r[mid] > key) {
			right = mid - 1;
		}
		else if (r[mid] < key) {
			left = mid + 1;
		}
	}
	if (key > r[mid]) {
		mid++;
	}
	return mid;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		int key;
		cin >> t;
		if (t == "Push") {
			scanf("%d", &key);
			s.push_back(key);
			r.insert(r.begin() + find(key), key);
		}
		else if (t == "Pop") {
			if (s.empty()) {
				printf("Invalid\n");
			}
			else {
				printf("%d\n", s.back());
				r.erase(r.begin() + find(s.back()));
				s.pop_back();
			}
		}
		else if (t == "PeekMedian") {
			if (s.empty()) {
				printf("Invalid\n");
			}
			else {
				int mid = s.size() % 2 == 0 ? s.size() / 2 : (s.size() + 1) / 2;
				printf("%d\n", r[mid - 1]);
			}
		}
	}
	return 0;
}