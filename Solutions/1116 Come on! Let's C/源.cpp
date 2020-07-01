#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;
// ID:Rank
unordered_map<int, int> check;
/*
0: "Checked"
1: "Mystery Award"
2: "Minion"
3: "Chocolate"
4: "Are you kidding?"
*/
vector<string> status{ "Checked","Mystery Award","Minion","Chocolate","Are you kidding?" };
void output(int statusCode) {
	//if (statusCode < 0 || statusCode > 4) {
	//	return;
	//}
	printf("%s\n", status[statusCode].c_str());
}
bool isPrime(int x) {
	for (int i = sqrt(x); i > 1; i--) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int N, K, temp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		check[temp] = i;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		scanf("%d", &temp);
		printf("%04d: ", temp);
		if (check.find(temp) == check.end()) {
			output(4);
		}
		else if (check[temp] == 0) {
			output(0);
		}
		else {
			if (check[temp] == 1) {
				output(1);
			}
			else if (isPrime(check[temp])) {
				output(2);
			}
			else {
				output(3);
			}
			check[temp] = 0;
		}
	}
	return 0;
}