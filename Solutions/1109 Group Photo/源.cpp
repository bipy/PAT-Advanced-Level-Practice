#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
struct node {
	string name;
	int height;
};
vector<node> v;
bool cmp(const node& a, const node& b) {
	if (a.height == b.height) {
		return a.name > b.name;
	}
	return a.height < b.height;
}
int main() {
	int K, N;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		int h;
		cin >> s >> h;
		v.push_back(node{ s,h });
	}
	// 按身高排序
	sort(v.begin(), v.end(), cmp);
	// 每行人数
	int rowLimit = N / K;
	// 最后一行人数
	int maxRow = rowLimit + N % K;
	// 作为“行”的容器
	vector<node> row(maxRow, node{ "null",0 });
	// 偏移值，打表
	vector<int> offset(maxRow);
	for (int i = 0; i < maxRow; i++) {
		offset[i] = pow(-1, i) * ((i+1) / 2);
	}
	for (int i = K; i > 0; i--) {
		int start = (i - 1) * rowLimit;
		int end = i == K ? N : i * rowLimit;
		int root = (end - start) / 2;
		int index = 0;
		// 中心+偏移即为对应位置
		for (int j = end - 1; j >= start; j--) {
			row[root + offset[index]] = v[j];
			index++;
		}
		// 输出
		bool blankSpace = false;
		for (int k = 0; k < maxRow; k++) {
			// null代表没人在这个位置
			if (row[k].name != "null") {
				if (blankSpace) {
					cout << " ";
				}
				cout << row[k].name;
				blankSpace = true;
			}
		}
		cout << endl;
		// 必须要clear，只resize不行
		row.clear();
		row.resize(maxRow, node{ "null",0 });
	}
	return 0;
}