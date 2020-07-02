#include<iostream>
#include<vector>
using namespace std;
// 并查集
vector<int> v(10010, 0);
// 找到给定元素 x 的根
int findRoot(int x) {
	while (v[x] > 0) {
		x = v[x];
	}
	return x;
}
int main() {
	int N, K, Q, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &K);
		int picRoot;
		// 将所有元素的根连在第一个元素上，第一个元素成为新根，值为-1
		for (int j = 0; j < K; j++) {
			scanf("%d", &temp);
			int curRoot = findRoot(temp);
			if (j == 0) {
				picRoot = curRoot;
				v[picRoot] = -1;
			}
			else {
				v[curRoot] = picRoot;
			}
		}
	}
	// 计数，并把层数削减到1
	int countTree = 0, countBrid = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		if (*it != 0) {
			countBrid++;
			if (*it == -1) {
				countTree++;
			}
			else {
				*it = findRoot(*it);
			}	
		}
	}
	printf("%d %d\n", countTree, countBrid);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf(findRoot(a) == findRoot(b) ? "Yes\n" : "No\n");
	}
	return 0;
}