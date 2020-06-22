#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int>  pre, in, post, stack;
void trans(int in_left, int in_right, int pre_root) {
	if (in_left > in_right) {
		return;
	}
	int index = in_left;
	while (index < in_right && in[index] != pre[pre_root]) index++;
	trans(in_left, index - 1, pre_root + 1);
	trans(index + 1, in_right, pre_root + index - in_left + 1);
	post.push_back(pre[pre_root]);
}
int main() {
	//freopen("Text.txt", "r", stdin);
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < 2 * n; i++) {
		string s;
		//getline(cin, s);
		//此处使用getline需要注意Push的数字大于10的问题
		cin >> s;
		if (s == "Pop") {
			in.push_back(stack.back());
			stack.pop_back();
		}
		else {
			int temp;
			cin >> temp;
			stack.push_back(temp);
			pre.push_back(temp);
		}
	}
	trans(0, n - 1, 0);
	for (auto it = post.begin(); it != post.end(); it++) {
		it == post.begin() ? printf("%d", *it) : printf(" %d", *it);
	}
	return 0;
}
