#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	}
	else if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else {
		assert(0);
	}
}

long long maxa(long long mc, long long a, long long b, long long c, long long d)
{
	long long max_ = mc;
	if (max_ < a)
		max_ = a;
	if (max_ < b)
		max_ = b;
	if (max_ < c)
		max_ = c;
	if (max_ < d)
		max_ = d;
	return max_;
}
long long mina(long long mc, long long a, long long b, long long c, long long d)
{
	long long min_ = mc;
	if (min_ > a)
		min_ = a;
	if (min_ > b)
		min_ = b;
	if (min_ > c)
		min_ = c;
	if (min_ > d)
		min_ = d;
	return min_;
}
vector<long long> MinAndMax(long long i, long long j, vector<vector<vector<long long>>> mM, const string& exp)
{
	long long max1 = LLONG_MIN; //先定义的是int导致溢出
	long long min1 = LLONG_MAX;
	for (long long k = i; k <= j - 1; k++)
	{
		long long val1 = eval(mM[i - 1][k - 1][1], mM[k][j - 1][1], exp[2 * k - 1]);
		long long val2 = eval(mM[i - 1][k - 1][1], mM[k][j - 1][0], exp[2 * k - 1]);
		long long val3 = eval(mM[i - 1][k - 1][0], mM[k][j - 1][1], exp[2 * k - 1]);
		long long val4 = eval(mM[i - 1][k - 1][0], mM[k][j - 1][0], exp[2 * k - 1]);
		max1 = maxa(max1, val1, val2, val3, val4);
		min1 = mina(min1, val1, val2, val3, val4);
	}
    vector<long long> kk{ min1, max1 };
	return kk;
}
long long get_maximum_value(const string &exp) {
	//write your code here
	int digit_size = (exp.size() + 1) / 2;
	vector<vector<vector<long long>>> mM(digit_size, vector<vector<long long>>(digit_size, vector<long long> {LLONG_MAX, LLONG_MIN}));
	for (int i = 1; i <= digit_size;i++)
	{
		mM[i - 1][i - 1][0] = exp[2*i - 2] - '0';
		mM[i - 1][i - 1][1] = exp[2*i - 2] - '0';
	}
	for (int s = 1; s <= digit_size - 1; s++)
	{
		for (int i = 1; i <= digit_size - s; i++)
		{
			int j = i + s;
			mM[i - 1][j - 1][0] = (MinAndMax(i, j, mM, exp))[0];
			mM[i - 1][j - 1][1] = (MinAndMax(i, j, mM, exp))[1];
		}
	}
	return mM[0][digit_size - 1][1];
}

int main() {
	string s;
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
	system("pause");
	return 0;
}
