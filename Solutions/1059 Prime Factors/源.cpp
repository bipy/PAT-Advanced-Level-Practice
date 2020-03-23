#include<iostream>
#include<map>
#include<cmath>
using namespace std;
map<long int, int> seq;
void add(long int v) {
	if (seq.count(v) == 0) {
		seq[v] = 1;
	}
	else {
		seq[v]++;
	}
}
int main() {
	long int n, ter;
	cin >> n;
	printf("%ld=", n);
	ter = sqrt(n);
	for (long int i = 2; i <= ter; i++) {
		if (n % i == 0) {
			add(i);
			n /= i;
			ter = sqrt(n);
			i = 1;
		}
	}
	add(n);
	bool flag = false;
	for (auto it = seq.begin(); it != seq.end(); it++) {
		if (flag) {
			printf("*");
		}
		if (it->second > 1) {
			printf("%ld^%d", it->first, it->second);
		}
		else {
			printf("%ld", it->first);
		}
		flag = true;
	}
	return 0;
}