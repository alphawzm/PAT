// 1010. Radix (25)
// 使用二分查找
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 给定一个string型数值和一个radix进制，将它转化为10进制。转化过程中可能产生溢出。
// N是10位数字，radix，sum设置为long long型
long long convert(string n, long long radix) {
	long long sum = 0;
	int index = 0, temp = 0;
	for (auto i = n.rbegin(); i != n.rend(); i++) {
		// 当前位为数字还是字母
		temp = isdigit(*i) ? *i - '0' : *i - 'a' + 10;
		sum += temp * pow(radix, index++);
	}
	return sum;
}
// 找到使两个数值相等的进制数。
// 在查找的过程中，使用二分查找算法。
// 如果使用当前进制转化得到数值小于0或比另一个数值大，说明这个进制太大；
// 如果使用当前进制转化得到数值大于0或且比另一个数值小，说明这个进制太小。
// 找到使两个数值相等的进制数，则返回非0数，否则返回-1。
long long find_radix(string n, long long num) {
	char i = *max_element(n.begin(), n.end());
	// low_radix 对于只有一位数值的数，最小进制为一位数值+1
	// high_radix 一个位数大于一位的数，进制最大为num数值
	long long low_radix = (isdigit(i) ? i - '0' : i - 'a' + 10) + 1;
	long long high_radix = max(num, low_radix);
	while (low_radix <= high_radix) {
		long long mid_radix = (low_radix + high_radix) / 2;
		long long result_num = convert(n, mid_radix);
		if (result_num < 0 || result_num > num) high_radix = mid_radix - 1;
		else if (result_num == num) return mid_radix;
		else low_radix = mid_radix + 1;
	}
	return -1;
}
int main() {
	string n1, n2;
	long long tag = 0, radix = 0, result_radix;
	cin >> n1 >> n2 >> tag >> radix;
	// 找到使两个数值相等的进制数
	result_radix = (tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix)));
	if (result_radix != -1) {
		printf("%lld", result_radix);
	}
	else {
		printf("Impossible");
	}
	return 0;
}