#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int max(int a, int b, int c)
{
	int d = INT_MIN;
	if (d < a)
		d = a;
	if (d < b)
		d = b;
	if (d < c)
		d = c;
	return d;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	//write your code here
	vector < vector < vector<int>>> v(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1, 0)));
	for (int i = 1; i < a.size() + 1; i++)
	{
		for (int j = 1; j < b.size() + 1; j++)
		{
			for (int k = 1; k < c.size() + 1; k++)
			{
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					v[i][j][k] = v[i - 1][j - 1][k - 1] + 1;
				else
					v[i][j][k] = max(v[i - 1][j][k], v[i][j - 1][k], v[i][j][k - 1]);
			}
		}
	}
	return v[a.size()][b.size()][c.size()];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) {
		std::cin >> a[i];
	}
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) {
		std::cin >> b[i];
	}
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) {
		std::cin >> c[i];
	}
	std::cout << lcs3(a, b, c) << std::endl;
	system("pause");
	return 0;
}