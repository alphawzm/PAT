// 1011. World Cup Betting (20)
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char S[3] = { 'W','T','L' };
	double sum = 1.0, tmp, a;
	int index;   //记录每行最大数字的下标
	for (int i = 0; i < 3; i++) {
		tmp = 0.0;
		for (int j = 0; j < 3; j++) { 
			cin >> a;
			if (a > tmp) {
				tmp = a;
				index = j;
			}
		}
		sum *= tmp;
		cout << S[index] << " ";
	}
	cout << setprecision(4) << (sum * 0.65 - 1) * 2;
	return 0;
}