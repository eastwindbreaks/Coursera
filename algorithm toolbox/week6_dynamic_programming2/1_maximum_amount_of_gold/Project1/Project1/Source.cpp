#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
	//write your code here
	vector<vector<int>> W_weight(W + 1, vector<int> (w.size() + 1, INT_MIN));
	for (int i = 0; i < w.size() + 1; i++)
	{
		W_weight[0][i] = 0;
	}
	for (int j = 0; j < W + 1; j++)
	{
		W_weight[j][0] = 0;
	}
    for (int i = 1; i <= w.size(); i++)
	{
		for (int j = 1; j <= W; j++)
		{
			W_weight[j][i] = W_weight[j][i - 1];
			int val = INT_MIN;
			if (w[i - 1] <= j)
			{
				val = W_weight[j - w[i - 1]][i - 1] + w[i - 1];
				if (val > W_weight[j][i])
					W_weight[j][i] = val;
			}
		}
	}
	return W_weight[W][w.size()];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
	system("pause");
	return 0;
}
