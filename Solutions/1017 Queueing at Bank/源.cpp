#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct usr {
	int arr;
	int cost;
}temp;
bool cmp(usr a, usr b) {
	return a.arr < b.arr;
}
int main() {
	vector<usr> list;
	int N, K, wait = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int hour, minute, second, cost;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &cost);
		temp.arr = hour * 60 * 60 + minute * 60 + second;
		temp.cost = cost * 60;
		if (temp.arr <= 61200) {
			list.push_back(temp);
		}
	}
	if (list.size() == 0) {
		printf("0.0");
		return 0;
	}
	sort(list.begin(), list.end(), cmp);
	vector<int> window(K, 28800);
	for (int i = 0; i < list.size(); i++) {
		int min = 0;
		for (int j = 1; j < K; j++) {
			if (window[min] > window[j]) {
				min = j;
			}
		}
		if (window[min] > list[i].arr) {
			wait += window[min] - list[i].arr;
			window[min] += list[i].cost;
		}
		else {
			window[min] = list[i].arr + list[i].cost;
		}
	}
	printf("%.1f", wait / 60.0 / list.size());
	return 0;
}