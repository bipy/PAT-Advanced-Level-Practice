#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, bool> m;
int main() {
	int n, temp, index = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		m[temp] = true;
	}
	while (m[++index] == true);
	cout << index;
	return 0;
}