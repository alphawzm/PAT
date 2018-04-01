// 1009. Product of Polynomials(25)
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int n1, n2, exp, cnt = 0;
	double coe;

	cin >> n1;
	double arr[1001] = { 0.0 };
	double ans[2001] = { 0.0 };
	for (int i = 0; i < n1; i++) {
		cin >> exp >> coe;
		arr[exp] = coe;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> exp >> coe;
		for (int j = 0; j < 1001; j++) {
			if (arr[j] != 0.0) {
				ans[j + exp] += arr[j] * coe;
			}
		}
	}
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0.0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0.0) {
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}