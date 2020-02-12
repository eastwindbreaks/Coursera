#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
	if (left == right) return -1;
	if (left + 1 == right) return a[left];
	//write your code here
	int mid = left + (right - 1 - left) / 2;
	int left_majority = get_majority_element(a, left, mid + 1);
	int right_majority = get_majority_element(a, mid + 1, right);
	if (left_majority != -1)
	{
		int count_left = 0;
		for (int i = left; i < right; i++)
		{
			if (a[i] == left_majority)
				count_left++;
		}
		if (count_left > (right - left) / 2)
			return left_majority;
	}
	if (right_majority != left_majority && right_majority != -1)
	{
		int count_right = 0;
		for (int i = left; i < right; i++)
		{
			if (a[i] == right_majority)
				count_right++;
		}
		if (count_right >(right - left) / 2)
			return right_majority;
	}
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	//std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
	std::unordered_map<int, int> my_map;
	for (auto v : a)
	{
		my_map[v]++;
	}
	for (auto v : my_map)
	{
		if (v.second > a.size() / 2)
			std::cout << 1 << std::endl;
		system("pause");
		return 0;
	}
	std::cout << 0 << std::endl;
	system("pause");
	return 0;
}
