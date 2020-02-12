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
	for (long long i = 2; ; i++) //这里千万不要限定小于n， 有可能n还没有周期数大
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
			previous1 = previous2 % m; //这一步加取模十分重要，否则后面的大的fibonacci数没法存储
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
