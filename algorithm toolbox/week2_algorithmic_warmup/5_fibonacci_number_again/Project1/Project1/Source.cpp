#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge_fast(long long n, long long m) {
	if (n <= 1)
		return n;
	vector<long long> arr;
	arr.push_back(0);
	arr.push_back(1);
	int64_t previous1 = 0;
	int64_t previous2 = 1;
	int64_t current;
	for (long long i = 2; ; i++) //����ǧ��Ҫ�޶�С��n�� �п���n��û����������
	{
		current = previous1 + previous2;
		arr.push_back(current % m);
		if (arr[arr.size() - 1] == 1 && arr[arr.size() - 2] == 0)
		{
			arr.pop_back();
			arr.pop_back();
			break;
		}
		else
		{
			previous1 = previous2 % m; //��һ����ȡģʮ����Ҫ���������Ĵ��fibonacci��û���洢
			previous2 = current % m;
		}
	}
	return arr[n % arr.size()];
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonacci_huge_fast(n, m) << endl;
	system("pause");
	return 0;
}
