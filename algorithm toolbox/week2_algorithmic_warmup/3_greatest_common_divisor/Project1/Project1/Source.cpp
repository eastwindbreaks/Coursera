#include <iostream>

/*int gcd_naive(int a, int b) {
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
			if (d > current_gcd) {
				current_gcd = d;
			}
		}
	}
	return current_gcd;
}*/

int gcd_fast(int a, int b)
{
	int temp;
	if (a == b)
		return a;
	else if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (a % b != 0)
	{
		int remainder = a % b;
		int temp;
		if (b < remainder)
		{
			temp = b;
			b = remainder;
			remainder = temp;
		}
		a = b;
		b = remainder;
	}
	return b;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	//std::cout << gcd_naive(a, b) << std::endl;
	std::cout << gcd_fast(a, b) << std::endl;
	system("pause");
	return 0;
}
