#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
struct node {
	int address, data, next;
};
unordered_map<int, node> m;
vector<node> ans;
int main() {
	int head, n, k;
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++) {
		node temp;
		scanf("%d%d%d", &temp.address, &temp.data, &temp.next);
		m[temp.address] = temp;
	}
	for (int i = 1; i <= 3; i++) {
		int index = head;
		while (index != -1) {
			if (i == 1 && m[index].data < 0 || i == 2 && m[index].data >= 0 && m[index].data <= k || i == 3 && m[index].data > k) {
				ans.push_back(m[index]);
			}
			index = m[index].next;
		}
	}
	for (int i = 0; i < ans.size() - 1; i++) {
		printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address);
	}
	printf("%05d %d -1", ans[ans.size() - 1].address, ans[ans.size() - 1].data);
	return 0;
}