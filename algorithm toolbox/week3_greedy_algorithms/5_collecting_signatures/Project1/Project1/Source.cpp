/*#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	int start, end;
};

bool comparefunction(Segment i, Segment j)
{
	return i.end < j.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	//write your code here
	sort(segments.begin(), segments.end(), comparefunction);
	for (size_t i = 0; i < segments.size(); ) { //size_t, Alias of one of the fundamental unsigned integer types.
		int current_end = segments[i].end;
		while (i < segments.size() && segments[i].start <= current_end)
		{
			i++;
		}
		points.push_back(current_end);
	}
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
	system("pause");
	return 0;
}*/

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	int start, end;
};

bool sortFunction(Segment i, Segment j) { return (i.end < j.end); }

vector<int> optimal_points(vector <Segment> &segments) {

	std::sort(segments.begin(), segments.end(), sortFunction);

	vector<int> points;
	int point = segments[0].end;
	points.push_back(point);

	for (size_t i = 1; i < segments.size(); ++i) {
		if (point < segments[i].start) { //这种方法更高效，其实就是比较所有点的start和当前end的关系
			point = segments[i].end;
			points.push_back(point);
		}
	}
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector <Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
	return 0;
}