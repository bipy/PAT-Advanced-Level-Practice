#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> seq(N + 1);
    double temp;
    for (int i = 1; i <= N; i++) {
        scanf("%lf", &temp);
        seq[i] = temp * 1000;
    }
    long long sum = seq[N];
    for (int i = N - 1; i > 0; i--) {
        seq[i] = seq[i + 1] + seq[i] * (N - i + 1);
        sum += seq[i];
    }
    printf("%.2f", sum / 1000.0);
    return 0;
}