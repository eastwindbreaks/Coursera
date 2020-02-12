#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;


int compute_min_refills(int dist, int tank, vector<int> & stops) {
	// write your code here
	int num = 0;
	int n = stops.size();
	stops.insert(stops.begin(), 0);
	stops.push_back(dist); //为了方便解答，把终点加到加油站里面
	int currentrefill = 0;
	while (currentrefill <= n)
	{
		int lastrefill = currentrefill;
		while (currentrefill <= n && stops[currentrefill + 1] - stops[lastrefill] <= tank)
		{
			currentrefill++;
		}
		if (currentrefill == lastrefill)
			return -1;
		if (currentrefill <= n)
			num = num + 1;
	}
	return num;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";
	system("pause");
	return 0;
}