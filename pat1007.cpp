// 1007. Maximum Subsequence Sum(25)
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	int max_sum, now_sum, first, last, now_first, now_last;
	now_sum = first = last = max_sum = now_first = now_last = seq[0];
	for (int i = 1; i < n; i++)
	{
		if (now_sum > 0)	
		{
			now_sum += seq[i];
			now_last = seq[i];
		}
		else
		{
			now_first = now_last = seq[i];
			now_sum = seq[i];
		}

		if (now_sum > max_sum)	
		{
			first = now_first;
			last = now_last;
			max_sum = now_sum;
		}

	}
	if (max_sum < 0)	
		cout << 0 << " " << seq[0] << " " << seq[n - 1] << endl;
	else
		cout << max_sum << " " << first << " " << last << endl;
	return 0;
}