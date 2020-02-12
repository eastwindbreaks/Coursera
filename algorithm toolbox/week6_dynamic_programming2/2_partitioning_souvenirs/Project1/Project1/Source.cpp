#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
	//write your code here
	int sum = 0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += A[i];
	}
	if (sum % 3 != 0)
		return 0;
	vector<vector<vector<int>>> boolean_v(sum / 3 + 1, vector<vector<int>>(sum / 3 + 1, vector<int>(A.size() + 1, 0)));
	for (int i = 0; i < A.size() + 1; i++)
	{
		boolean_v[0][0][i] = 1;  //即不分配，所以是1 也就是ture
	}
	for (int m = 0; m < sum /3 + 1; m++)
	{
		for (int n = 0; n < sum / 3 + 1; n++)
		{
			if (m == 0 && n == 0)
			{
				boolean_v[m][n][0] = 1;
			}
		}
	}
	for (int i = 0; i < sum / 3 + 1; i++)
	{
		for (int j = 0; j < sum / 3 + 1; j++)
		{
			for (int m = 1; m < A.size() + 1; m++)
			{
				boolean_v[i][j][m] = boolean_v[i][j][m - 1];
				if (A[m - 1] <= i && A[m - 1] > j)
				{
					boolean_v[i][j][m] = boolean_v[i - A[m - 1]][j][m - 1] || boolean_v[i][j][m - 1];
				}
				else if (A[m - 1] <= j && A[m - 1] > i)
				{
					boolean_v[i][j][m] = boolean_v[i][j - A[m - 1]][m - 1] || boolean_v[i][j][m - 1];
				}
				else if (A[m - 1] <= j && A[m - 1] <= i)
				{
					boolean_v[i][j][m] = boolean_v[i - A[m - 1]][j][m - 1] || boolean_v[i][j][m - 1] || boolean_v[i][j - A[m - 1]][m - 1];
				}
				//std::cout << i << j << m << " " << boolean_v[i][j][m] << std::endl;
			}
		}
	}
	return boolean_v[sum / 3][sum / 3][A.size()];
}

int main() {
	int n;
	std::cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) {
		std::cin >> A[i];
	}
	std::cout << partition3(A) << '\n';
	system("pause");
	return 0;
}
