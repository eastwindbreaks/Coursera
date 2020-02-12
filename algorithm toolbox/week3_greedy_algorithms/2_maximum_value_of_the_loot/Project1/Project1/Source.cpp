#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> //greater, change the order
#include <map>
#include <iomanip>
#define min(a, b) (a < b ? a : b)

using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
    map<double, int, greater<double>> valuesdivideweights; //compare key to decide the order
	for (int i = 0; i < weights.size(); i++)
	{
		valuesdivideweights.insert(pair<double, int> (double(values[i]) / double(weights[i]), weights[i]));
	}

	map<double, int>::iterator it = valuesdivideweights.begin();
	while (capacity >= 0)
	{
		if (it != valuesdivideweights.end())
		{
			int current_weight = min(it->second, capacity);
			value += it->first * double(current_weight);
			capacity = capacity - current_weight;
			it++;
		}
		else return value;
	}
	return value;
}

int main() {
	int n;
	int capacity;
	cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	cout << fixed << setprecision(4) << optimal_value << endl;
	system("pause");
	return 0;
}
