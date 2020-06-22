#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<string>
#include<unordered_map>
using namespace std;
//struct seg {
//	int left, right;
//};
//deque<seg> q;
int main() {
	//freopen("Text.txt", "r", stdin);
	int N, p;
	cin >> N >> p;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int maxCount = 0, last = 0;
	for (int i = 0; i < v.size(); i++) {
		int left = i, right = N - 1, mid = i;
		long long cross = (long long)p * v[i];
		//二分法，返回选定mid的后一位，如果mid是最后则手动+1
		while (left <= right) {
			mid = (left + right) / 2;
			if (cross >= v[mid]) {
				left = mid + 1;
				if (mid == N - 1) {
					mid = N;
					break;
				}
			}
			else if (cross < v[mid]) {
				right = mid - 1;
			}
		}
		if (mid - i > maxCount) {
			maxCount = mid - i;
		}
		if (N - i < maxCount) {
			break;
		}
	}
	cout << maxCount;
	/*
	BFS超时
	*/
	//q.push_back(seg{ 0,N - 1 });
	//while (!q.empty()) {
	//	seg cur = q.front();
	//	if (p >= double(v[cur.right])/v[cur.left]) {
	//		cout << cur.right - cur.left + 1;
	//		break;
	//	}
	//	else if (cur.right > cur.left) {
	//		q.push_back(seg{ cur.left + 1,cur.right });
	//		q.push_back(seg{ cur.left,cur.right - 1 });
	//	}
	//	q.pop_front();
	//}
	return 0;
}