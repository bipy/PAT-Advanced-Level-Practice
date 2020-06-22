#include<iostream>
#include<unordered_map>
using namespace std;
struct node {
	int next;
	bool visited = false;
};
int main() {
	unordered_map<int, node> m;
	int s1, s2, n, k;
	cin >> s1 >> s2 >> n;
	for (int i = 0; i < n; i++) {
		node temp;
		char c;
		scanf("%d %c %d", &k, &c, &temp.next);
		m[k] = temp;
	}
	for (int i = s1; i != -1; i = m[i].next) {
		m[i].visited = true;
	}
	for (int i = s2; i != -1; i = m[i].next) {
		if (m[i].visited == true) {
			printf("%05d", i);	//注意输出格式
			return 0;
		}
	}
	printf("-1");
	return 0;
}