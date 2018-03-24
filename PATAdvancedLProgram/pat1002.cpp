// 1002. A + B for Polynomials(25)

#include <iostream>
#include <cstdio>
using namespace std;

double a[1001], b[1001];
int main()
{
	int i;
	int k, expo;
	double coef;
	
	for (i = 0; i <= 1000; i++) 
		a[i] = b[i] = 0;
	
	cin >> k;
	for (i = 1; i <= k; i++)
	{
		cin >> expo >> coef;
		a[expo] = coef;
	}
	cin >> k;
	for (i = 1; i <= k; i++)
	{
		cin >> expo >> coef;
		b[expo] = coef;
	}
	int k_sum = 0;
	for (i = 0; i <= 1000; i++)
	{
		a[i] += b[i];
		if (a[i]) k_sum++;
	}
	cout << k_sum;

	for (i = 1000; i >= 0; i--)
	{
		if (a[i])    printf(" %d %.1lf", i, a[i]);
	}
	return 0;
}