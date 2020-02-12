#include <iostream>

long long lcm_fast(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	if (a == b)
		return (long long) b;
	int temp;
	int mul1 = a;
	int mul2 = b;
	if (a < b)
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
    
	return (long long) (mul1 / b) * (long long) (mul2 / b) * (long long) (b);
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm_fast(a, b) << std::endl;
	system("pause");
	return 0;
}
