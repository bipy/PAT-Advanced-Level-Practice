#include<iostream>
#define radix 13
using namespace std;
int main() {
	int rgb;
	char trans[14] = { "0123456789ABC" };
	printf("#");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &rgb);
		printf("%c%c", trans[rgb / radix], trans[rgb % radix]);
	}
	return 0;
}