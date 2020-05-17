#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	double v, ans = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%lf", &v);
		ans += v * i * (N - i + 1);
	}
	printf("%.2f", ans);
	return 0;
}