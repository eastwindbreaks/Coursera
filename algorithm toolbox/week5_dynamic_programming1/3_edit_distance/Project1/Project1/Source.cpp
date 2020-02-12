#include <iostream>
#include <string>
#include <vector>
#include <climits>

using std::string;
using namespace std;

int MIN_COMPARE(int a, int b, int c)
{
	int min_c = INT_MAX;
	if (a < min_c)
	{
		min_c = a;
	}
	if (b < min_c)
	{
		min_c = b;
	}
	if (c < min_c)
	{
		min_c = c;
	}
	return min_c;
}

int edit_distance(const string &str1, const string &str2) {
	//write your code here
	/*if (str1.size() == 0)
		return str2.size();
	else if (str2.size() == 0)
		return str1.size();*/ //可以不要，题干说字符串长度至少1
	vector<vector<int>> cost(str1.size() + 1, vector<int> (str2.size() + 1, INT_MAX));
	cost[0][0] = 0;
	for (int m = 0; m < str2.size(); m++)
	{
		cost[0][m + 1] = m + 1;
	}
	for (int n = 0; n < str1.size(); n++)
	{
		cost[n + 1][0] = n + 1;
	}
	size_t i;
	size_t j;
	for (i = 0; i < str1.size(); i++)
	{
		for (j = 0; j < str2.size(); j++)
		{
			int edit_insertion =cost[i + 1][j + 1 - 1] + 1;
			int edit_deletion = cost[i  + 1 - 1][j + 1] + 1;
			int edit_match = cost[i + 1 - 1][j + 1 - 1];
			int edit_mismatch = cost[i + 1 - 1][j + 1 - 1] + 1;
			if (str1[i] == str2[j])
			{
				cost[i + 1][j + 1] = MIN_COMPARE(edit_insertion, edit_deletion, edit_match);
			}
			else if (str1[i] != str2[j])
			{
				cost[i + 1][j + 1] = MIN_COMPARE(edit_insertion, edit_deletion, edit_mismatch);
			}
		}
	}
	return cost[str1.size()][str2.size()];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	system("pause");
	return 0;
}