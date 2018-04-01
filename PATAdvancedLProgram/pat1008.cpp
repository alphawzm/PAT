// 1008. Elevator (20)
#include <iostream>
using namespace std;
int main() {
	int n,f;
	while (cin >> n) {
		int cur = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			
			cin >> f;
			sum += (f > cur) ? (f - cur) * 6 : (cur - f) * 4;
			cur = f;
		}
		sum += n * 5;
		cout << sum;
	}
	return 0;
}