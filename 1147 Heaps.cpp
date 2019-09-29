#include<iostream>
#include<vector>
using namespace std;
vector<int> heap;
bool space = true;
void postorder(int cur) {
	if (cur * 2 < heap.size()) {
		postorder(cur * 2);
	}
	if (cur * 2 + 1 < heap.size()) {
		postorder(cur * 2 + 1);
	}
	space == true ? space = false : printf(" ");
	printf("%d", heap[cur]);
}
int main() {
	freopen("Text.txt", "r", stdin);
	int m, n;
	cin >> m >> n;
	heap.resize(n + 1);
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &heap[j]);
		}
		bool flag = true;
		if (heap[1] >= heap[2]) {
			for (int k = 1; k <= n / 2 + 1; k++) {
				if (2 * k <= n && heap[k] < heap[2 * k] || 2 * k + 1 <= n && heap[k] < heap[2 * k + 1]) {
					flag = false;
					break;
				}
			}
			flag == true ? printf("Max Heap\n") : printf("Not Heap\n");
		}
		else if (heap[1] < heap[2]) {
			for (int k = 1; k <= n / 2 + 1; k++) {
				if (2 * k <= n && heap[k] >= heap[2 * k] || 2 * k + 1 <= n && heap[k] >= heap[2 * k + 1]) {
					flag = false;
					break;
				}
			}
			flag == true ? printf("Min Heap\n") : printf("Not Heap\n");
		}
		space = true;
		postorder(1);
		printf("\n");
	}
	return 0;
}