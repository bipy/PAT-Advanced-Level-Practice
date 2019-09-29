#include<iostream>
#include<vector>
using namespace std;
vector<int> seq;
vector<vector<int> > ans;
void travel(int cur, vector<int> v) {
	if (2 * cur  >= seq.size() && 2 * cur + 1 >= seq.size()) {
		ans.push_back(v);
		return;
	}
	if (2 * cur + 1 < seq.size()) {
		vector<int> temp = v;
		temp.push_back(seq[2 * cur + 1]);
		travel(2 * cur + 1, temp);
	}
	if (2 * cur < seq.size()) {
		vector<int> temp = v;
		temp.push_back(seq[2 * cur]);
		travel(2 * cur, temp);
	}
}
int main() {
	int n, type;		//0:not, 1:max, 2:min
	cin >> n;
	seq.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &seq[i]);
	}
	if (seq[1] > seq[2]) {
		type = 1;
		for (int i = 1; i <= n / 2; i++) {
			if (i * 2 <= n && seq[i] < seq[i * 2] || i * 2 + 1 <= n && seq[i] < seq[i * 2 + 1]) {
				type = 0;
				break;
			}
		}
	}
	else if (seq[1] < seq[2]) {
		type = 2;
		for (int i = 1; i <= n / 2; i++) {
			if (i * 2 <= n && seq[i] > seq[i * 2] || i * 2 + 1 <= n && seq[i] > seq[i * 2 + 1]) {
				type = 0;
				break;
			}
		}
	}
	vector<int> v;
	v.push_back(seq[1]);
	travel(1, v);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			j == 0 ? printf("%d", ans[i][j]) : printf(" %d", ans[i][j]);
		}
		printf("\n");
	}
	string a[3] = { "Not Heap","Max Heap","Min Heap" };
	cout << a[type];
	return 0;
}