#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;

/*vector<int> optimal_sequence(int n) {  反例例如22就不适用
	std::vector<int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		if (n % 3 == 0) {
			n /= 3;
		}
		else if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n - 1;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}*/

int min_number(int &a, int &b, int &c)
{
	int min = a;
	if (b < a)
		min = b;
	if (c < min)
		min = c;
	return min;
}

vector<int> optimal_sequence(int n)
{
	vector<int> MIN_EACH(n + 1, 0);
	vector<int> previous_best(n + 1, 0);
	vector<int> sequence;
	for (int i = 2; i <= n; i++)
	{
		int num1 = MIN_EACH[i - 1] + 1;
		int num2 = INT_MAX;
		int num3 = INT_MAX;
		if (i % 2 == 0)
			num2 = MIN_EACH[i / 2] + 1;
		if (i % 3 == 0)
			num3 = MIN_EACH[i / 3] + 1;
		MIN_EACH[i] = min_number(num1, num2, num3);
		if (MIN_EACH[i] == num1)
			previous_best[i] = i - 1;
		else if (MIN_EACH[i] == num2)
			previous_best[i] = i / 2;
		else if (MIN_EACH[i] == num3)
			previous_best[i] = i / 3;
	}
	int temp = n;
	while (temp >= 2)
	{
		sequence.push_back(previous_best[temp]);
		temp = previous_best[temp];
	}
	reverse(sequence.begin(), sequence.end());
	sequence.push_back(n);
	return sequence;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
	system("pause");
	return 0;
}
