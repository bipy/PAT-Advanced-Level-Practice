#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> cp, cn, pp, pn;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t > 0) {
			cp.push_back(t);
		}
		else {
			cn.push_back(-t);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t > 0) {
			pp.push_back(t);
		}
		else {
			pn.push_back(-t);
		}
	}
	sort(cp.begin(), cp.end(), cmp);
	sort(cn.begin(), cn.end(), cmp);
	sort(pp.begin(), pp.end(), cmp);
	sort(pn.begin(), pn.end(), cmp);
	for(int i=0;i<cp.size()&&i<pp.size();i++) {
		sum += cp[i] * pp[i];
	}
	for (int i = 0; i < cn.size() && i < pn.size(); i++) {
		sum += cn[i] * pn[i];
	}
	printf("%d", sum);
	return 0;
}