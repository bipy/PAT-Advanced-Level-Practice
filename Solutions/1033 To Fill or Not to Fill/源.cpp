#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct station {
	double price, pos;
};
vector<station> list;
double cap, dist, cost, n, curgas = 0, total = 0;
int curpos = 0;
bool cmp(station a, station b) {
	return a.pos < b.pos;
}
int main() {
	cin >> cap >> dist >> cost >> n;
	station temp;
	for (int i = 0; i < n; i++) {
		cin >> temp.price >> temp.pos;
		list.push_back(temp);
	}
	temp.price = 0;
	temp.pos = dist;
	list.push_back(temp);
	sort(list.begin(), list.end(), cmp);
	if (list[curpos].pos > 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	while (curpos < n) {
		if (list[curpos + 1].pos > list[curpos].pos + cap * cost) {
			printf("The maximum travel distance = %.2f", list[curpos].pos + cap * cost);
			return 0;
		}
		int  min = curpos + 1, next = curpos;
		for (int i = curpos + 1; i <= n && list[i].pos <= list[curpos].pos + cap * cost; i++) {
			if (list[next].price > list[i].price) {
				next = i;
				break;
			}
		}
		if (next != curpos) {
			total += ((list[next].pos - list[curpos].pos) / cost - curgas) * list[curpos].price;
			curgas = 0;
			curpos = next;
		}
		else {
			for (int i = curpos + 1; i <= n && list[i].pos <= list[curpos].pos + cap * cost; i++) {
				if (list[min].price > list[i].price) {
					min = i;
				}
			}
			total += (cap - curgas) * list[curpos].price;
			curgas = cap - (list[min].pos - list[curpos].pos) / cost;
			curpos = min;
		}
	}
	printf("%.2f", total);
	return 0;
}