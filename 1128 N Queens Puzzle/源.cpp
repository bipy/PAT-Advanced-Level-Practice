#include<iostream>
#include<vector>
using namespace std;
struct node {
	int r, c;
};
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		vector<node> g;
		for (int j = 1; j <= num; j++) {
			node temp;
			scanf("%d", &temp.r);
			temp.c = j;
			g.push_back(temp);
		}
		bool flag = true;
		for (int j = 0; j < num - 1; j++) {
			for (int k = j + 1; k < num; k++) {
				if (g[j].c == g[k].c || g[j].r == g[k].r || g[j].r - g[k].r == g[j].c - g[k].c) {
					flag = false;
					break;
				}
			}
		}
		flag ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}