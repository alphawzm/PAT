// 1005. Spell It Right (20)

#include <iostream>
#include<string>
using namespace std;

int main() {
	string input;
	cin >> input;
	int sum = 0;
	for (int i = 0; i < input.length(); i++)
		sum += (input[i] - '0');
	string s = to_string(sum);
	string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	cout << arr[s[0] - '0'];
	for (int i = 1; i < s.length(); i++)
		cout << " " << arr[s[i] - '0'];
	return 0;
}