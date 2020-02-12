#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
	vector<int> summands;
	//write your code here
	int sum = 1;
	int i = 1;
	int org = n;
	summands.push_back(i);
	while (i + 1 <= (org - sum))
	{
		i++;
		summands.push_back(i);
		sum = sum + i;
	}
	if (org - sum > 0)
	{
		sum = sum - summands.back();
		summands.pop_back();
		summands.push_back(org - sum);
	}
	return summands;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << ' ';
	}
	system("pause");
	return 0;
}
