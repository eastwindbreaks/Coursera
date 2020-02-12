#include <iostream>

/*int get_fibonacci_last_digit_naive(int n) {
	if (n <= 1)
		return n;

	int previous = 0;
	int current = 1;

	for (int i = 0; i < n - 1; ++i) {
		int tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % 10;
}*/

int get_fibonacci_last_digit_fast(int n)
{
	int actual_n = n % 60; // final digit of fibonacci has a cycle length of 60
	int final_digit[60];
	final_digit[0] = 0;
	final_digit[1] = 1;
	if (actual_n <= 1)
		return actual_n;
	else
	{
		for (int i = 2; i <= actual_n; i++)
		{
			final_digit[i] = (final_digit[i - 2] + final_digit[i - 1]) % 10;
		}
		return final_digit[actual_n];
	}
}

int main() {
	int n;
	std::cin >> n;
	int c = get_fibonacci_last_digit_fast(n);
	std::cout << c << '\n';
	system("pause");
	return 0;
}
