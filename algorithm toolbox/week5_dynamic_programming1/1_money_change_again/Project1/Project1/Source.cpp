#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_change(int m) {
	//write your code here
	int coins[3] = { 1, 3, 4 };
	vector<int> MIN_each(m + 1, INT_MAX);
	MIN_each[0] = 0;
	if (m == 0)
	{
		return MIN_each[0];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i >= coins[j])
			{
				int NumCoins = MIN_each[i - coins[j]] + 1;
				if (NumCoins < MIN_each[i])
					MIN_each[i] = NumCoins;
			}
		}
	}
	return MIN_each[m];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
	system("pause");
	return 0;
}