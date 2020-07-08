#include<iostream>
#define maxK 1001
using namespace std;
int main() {
	//freopen("Text.txt", "r", stdin);
	int N, M, K, Q;
	int ptime[maxK] = { 0 }, wait[maxK] = { 0 }, gone[maxK] = { 0 }, line[maxK] = { 0 };
	cin >> N >> M >> K >> Q;
	for (int i = 1; i <= K; i++) {
		scanf("%d", &ptime[i]);
	}
	for (int i = 1; i <= K; i++) {
		if (i <= N) {
			wait[i] = ptime[i];
			line[i] = i;
		}
		else if (i <= N * M && i > N) {
			wait[i] = wait[i - N] + ptime[i];
			line[i] = i % N;
			if (line[i] == 0) {
				line[i] = N;
			}
		}
		else {
			int min = i - 1;
			for (int k = i - N * M; k < i; k++) {	//找到最早走的人，确定所在队
				if (gone[k] == 0 && wait[k] < wait[min]) {
					min = k;
				}
			}
			line[i] = line[min];
			gone[min] = 1;
			for (int j = i - 1; j > 0; j--) {	//找到所在队的最晚走的人
				if (line[j] == line[i]) {
					wait[i] = wait[j] + ptime[i];
					break;
				}
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		int num, hour, min;
		cin >> num;
		hour = wait[num] / 60 + 8;
		min = wait[num] % 60;
		//printf("%02d:%02d\n", hour, min);
		wait[num] - ptime[num] < 540 ? printf("%02d:%02d\n", hour, min) : printf("Sorry\n");
	}
	return 0;
}