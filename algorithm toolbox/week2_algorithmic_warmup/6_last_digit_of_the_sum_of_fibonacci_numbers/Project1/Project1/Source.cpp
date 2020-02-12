#include <iostream>
using namespace std;

int fibonacci_sum_last(long long n) {
	if (n <= 1)
		return n;
	int arr[60]; //把前n项和存在数组中
	arr[0] = 0;
	arr[1] = 1;
	int previous1 = 0;
	int previous2 = 1;
	int current;
	for (int i = 2; i < 60; i++)
	{
		current = (previous1 + previous2) % 10;
		arr[i] = (current + arr[i - 1]) % 10;
		previous1 = previous2 % 10;
		previous2 = current % 10;
	}
	long long number_cycle = (n + 1) / 60;
	return (number_cycle * arr[59] + arr[n % 60]) % 10;
}

int main() {
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_sum_last(n) << endl;
	system("pause");
	return 0;
}
