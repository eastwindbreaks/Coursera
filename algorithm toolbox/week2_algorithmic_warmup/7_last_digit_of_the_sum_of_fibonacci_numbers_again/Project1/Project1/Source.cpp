#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
	int arr[60];
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
	if (from == 0)
	{
		long long number_cycle = (to + 1) / 60;
		return (number_cycle * arr[59] + arr[to % 60]) % 10;
	}
	else
	{
		long long number_cycle_from = (from - 1 + 1) / 60; //ע���Fm��ʼ�Ļ�����������ǰ��m - 1 ��
		long long number_cycle_to = (to + 1) / 60; 
		int sum1 = (number_cycle_from * arr[59] + arr[(from - 1) % 60]) % 10;
		int sum2 = (number_cycle_to * arr[59] + arr[to % 60]) % 10;
		return sum1 > sum2 ? sum2 + 10 - sum1 : sum2 - sum1; //ע������Ҫ���ǽ�λ�����
	}
}

int main() {
	long long from, to;
	std::cin >> from >> to;
	std::cout << get_fibonacci_partial_sum_fast(from, to) << std::endl;
	system("pause");
	return 0;
}