#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

struct pairs
{
	int pos;
	char symbol;
	int index;
};

bool mycompare(pairs p1, pairs p2)
{
	if (p1.pos == p2.pos)
		return p1.symbol < p2.symbol;
	else
		return p1.pos < p2.pos;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	//write your code
	vector<pairs> p(starts.size() + ends.size() + points.size());
	for (size_t i = 0; i < starts.size(); i++)
	{
		p[i].pos = starts[i];
		p[i].symbol = 'l';
		p[i].index = i;
	}
	for (size_t i = starts.size(); i < starts.size() + ends.size(); i++)
	{
		p[i].pos = ends[i - starts.size()];
		p[i].symbol = 'r';
		p[i].index = i - starts.size();
	}
	for (size_t i = starts.size() + ends.size(); i < starts.size() + ends.size() + points.size(); i++)
	{
		p[i].pos = points[i - starts.size() - ends.size()];
		p[i].symbol = 'p';
		p[i].index = i - starts.size() - ends.size();
	}
	sort(p.begin(), p.end(), mycompare);
	int l_count = 0;
	int r_count = 0;
	for (auto v : p)
	{
		if (v.symbol == 'l')
			l_count++;
		else if (v.symbol == 'r')
			r_count++;
		else if (v.symbol == 'p')
		{
			cnt[v.index] = l_count - r_count;
		}
	}
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	for (size_t i = 0; i < points.size(); i++) {
		for (size_t j = 0; j < starts.size(); j++) {
			cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
		}
	}
	return cnt;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) {
		std::cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) {
		std::cin >> points[i];
	}
	//use fast_count_segment

	vector<int> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++) {
		std::cout << cnt[i] << ' ';
	}
	system("pause");
	return 0;
}
