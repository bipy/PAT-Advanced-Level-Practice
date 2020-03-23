#include<iostream>
#define up 6
#define down 4
#define stay 5
using namespace std;
int main() {
	int N, next, cur = 0, cost = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> next;
		if (next > cur) {
			cost += (next - cur) * up;
		}
		else if (next < cur) {
			cost += (cur - next) * down;
		}
		cur = next;
		cost += stay;
	}
	cout << cost;
	return 0;
}