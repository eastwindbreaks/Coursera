#include <iostream>
#include <vector>
#include <climits>

using std::vector;
int max(int a, int b)
{
	int c = INT_MIN;
	if (c < a)
		c = a;
	if (c < b)
		c = b;
	return c;
}
int lcs2(vector<int> &a, vector<int> &b)
{
	//write your code here
	vector<vector<int>> v(a.size() + 1, vector<int>(b.size() + 1, 0));
	for (size_t i = 1; i < a.size() + 1; i++)
	{
		for (size_t j = 1; j < b.size() + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
				v[i][j] = v[i - 1][j - 1] + 1;
			else
			{
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}
	return v[a.size()][b.size()];
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;
	system("pause");
	return 0;
}