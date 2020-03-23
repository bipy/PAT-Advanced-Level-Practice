#include<iostream>
#define gmax 10000000
#define smax 17
#define kmax 29
using namespace std;
int main() {
	int g1, g2, s1, s2, k1, k2, g, s, k, w = 0;
	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);
	if (k1 + k2 >= kmax) {
		k = k1 + k2 - kmax;
		w = 1;
	}
	else {
		k = k1 + k2;
	}
	s = s1 + s2 + w;
	if (s >= smax) {
		s -= smax;
		w = 1;
	}
	else {
		w = 0;
	}
	g = g1 + g2 + w;
	printf("%d.%d.%d", g, s, k);
	return 0;
}