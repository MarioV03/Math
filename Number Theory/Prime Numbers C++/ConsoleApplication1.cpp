//Sieve of Erathosphenes v1:
//Prints out all the prime numbers smaller than a specified integer

#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int nums[n];

	for (int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}


	for (int i = 1; i <= n; i++)
	{
		if (nums[i - 1] == 0 || nums[i - 1] == 1) { continue; }
		cout << i << endl;
		for (int j = i; j <= n; j += i)
		{
			nums[j - 1] = 0;
		}
	}

	return 0;
}