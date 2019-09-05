#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	double amount, price;
};
vector<node> l;
bool cmp(node a, node b) {
	return a.price > b.price;
}
int main() {
	int n, m;
	cin >> n >> m;
	l.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i].amount;
	}
	for (int i = 0; i < n; i++) {
		cin >> l[i].price;
		l[i].price /= l[i].amount;
	}
	sort(l.begin(), l.end(), cmp);
	double sum = 0, total = 0;
	for (int i = 0; i < n; i++) {
		if (m >= sum + l[i].amount) {
			sum += l[i].amount;
			total += l[i].price * l[i].amount;
		}
		else {
			total += (m - sum) * l[i].price;
			break;
		}
	}
	printf("%.2f", total);
	return 0;
}