#include<iostream>
#include<vector>
using namespace std;
vector<int> pre, in;
int ans = -1;
void process(int inleft, int inright, int preroot) {
	if (inleft > inright || ans != -1) {
		return;
	}
	int index;
	for (index = inleft; index <= inright; index++) {
		if (pre[preroot] == in[index]) {
			break;
		}
	}
	process(inleft, index - 1, preroot + 1);
	process(index + 1, inright, preroot + index - inleft + 1);
	if (ans == -1) {
		ans = pre[preroot];
	}
}
int main() {
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	process(0, n - 1, 0);
	cout << ans;
	return 0;
}