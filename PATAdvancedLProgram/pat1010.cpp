// 1010. Radix (25)
// ʹ�ö��ֲ���
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// ����һ��string����ֵ��һ��radix���ƣ�����ת��Ϊ10���ơ�ת�������п��ܲ��������
// N��10λ���֣�radix��sum����Ϊlong long��
long long convert(string n, long long radix) {
	long long sum = 0;
	int index = 0, temp = 0;
	for (auto i = n.rbegin(); i != n.rend(); i++) {
		// ��ǰλΪ���ֻ�����ĸ
		temp = isdigit(*i) ? *i - '0' : *i - 'a' + 10;
		sum += temp * pow(radix, index++);
	}
	return sum;
}
// �ҵ�ʹ������ֵ��ȵĽ�������
// �ڲ��ҵĹ����У�ʹ�ö��ֲ����㷨��
// ���ʹ�õ�ǰ����ת���õ���ֵС��0�����һ����ֵ��˵���������̫��
// ���ʹ�õ�ǰ����ת���õ���ֵ����0���ұ���һ����ֵС��˵���������̫С��
// �ҵ�ʹ������ֵ��ȵĽ��������򷵻ط�0�������򷵻�-1��
long long find_radix(string n, long long num) {
	char i = *max_element(n.begin(), n.end());
	// low_radix ����ֻ��һλ��ֵ��������С����Ϊһλ��ֵ+1
	// high_radix һ��λ������һλ�������������Ϊnum��ֵ
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
	// �ҵ�ʹ������ֵ��ȵĽ�����
	result_radix = (tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix)));
	if (result_radix != -1) {
		printf("%lld", result_radix);
	}
	else {
		printf("Impossible");
	}
	return 0;
}