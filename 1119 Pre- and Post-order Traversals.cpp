#include<iostream>
#include<vector>
using namespace std;
// 前 后 中
vector<int> pre, post, in;
// 判断是否唯一的标识符
bool flag = true;

void init(int N, vector<int>& curOrder) {
	curOrder.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &curOrder[i]);
	}
}

void getInOrder(int preL, int preR, int postL, int postR) {
	// 找到右节点
	// 其中rightRoot和leftRoot均是指pre的下标
	int rightRoot = preL + 1, leftRoot = preL + 1;
	for (int i = leftRoot; i <= preR; i++) {
		if (pre[i] == post[postR - 1]) {
			rightRoot = i;
			break;
		}
	}
	// 访问 左
	// if 左子树节点数大于0，非空，递归访问左子树
	// else 左子树为空，则另一子树可成为：（左子树 或 右子树），此时树不唯一，默认左子树为空
	if (rightRoot - leftRoot > 0) {
		getInOrder(leftRoot, rightRoot - 1, postL, postL + (rightRoot - leftRoot) - 1);
	}
	else if (preL != preR) {
		flag = false;
	}
	// 访问 中
	in.push_back(pre[preL]);
	// 如果右子树存在，访问 右
	if (preR - rightRoot + 1 > 0) {
		getInOrder(rightRoot, preR, postL + (rightRoot - leftRoot), postR - 1);
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);
	int N;
	// 输入
	cin >> N;
	init(N, pre);
	init(N, post);
	// 处理
	getInOrder(0, N - 1, 0, N - 1);
	// 输出
	printf(flag ? "Yes\n" : "No\n");
	printf("%d", in[0]);
	for (int i = 1; i < in.size(); i++) {
		printf(" %d", in[i]);
	}
	// 不加这句 “格式错误”
	printf("\n");
	return 0;
}