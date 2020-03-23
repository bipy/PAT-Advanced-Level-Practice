#include<iostream>
#include<vector>
using namespace std;
bool isMirror = false;
vector<int> pre, post;
void getpost(int root, int rear) {
	if (root > rear) {
		return;
	}
	int i = root + 1, j = rear;
	if (isMirror) {
		while (i <= rear && pre[i] >= pre[root]) {
			i++;
		}
		while (j > root && pre[j] < pre[root]) {
			j--;
		}
	}
	else {
		while (i <= rear && pre[i] < pre[root]) {
			i++;
		}
		while (j > root && pre[j] >= pre[root]) {
			j--;
		}
	}
	if (i - j != 1) {
		return;
	}
	getpost(root + 1, j);
	getpost(i, rear);
	post.push_back(pre[root]);
}
int main() {
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		pre.push_back(t);
	}
	getpost(0, n - 1);
	if (post.size() != pre.size()) {
		isMirror = true;
		post.clear();
		getpost(0, n - 1);
	}
	if (post.size() != pre.size()) {
		printf("NO");
	}
	else {
		printf("YES\n%d", post[0]);
		for (auto it = ++post.begin(); it != post.end(); it++) {
			printf(" %d", *it);
		}
	}
	return 0;
}