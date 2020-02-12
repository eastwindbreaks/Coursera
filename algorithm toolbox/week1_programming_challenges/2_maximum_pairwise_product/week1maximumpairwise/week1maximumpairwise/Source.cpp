#include <iostream>
#include <vector>
#include <algorithm>

int64_t MaxPairwiseProduct(const std::vector<int64_t>& numbers) {
	int n = numbers.size();
	int index1;
	int64_t large1 = 0, large2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] > large1)
		{
			large1 = numbers[i];
			index1 = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] > large2 && i != index1)
		{
			large2 = numbers[i];
		}
	}
	return large1 * large2;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int64_t> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	std::cout << MaxPairwiseProduct(numbers) << "\n";
	system("pause");
	return 0;
}
