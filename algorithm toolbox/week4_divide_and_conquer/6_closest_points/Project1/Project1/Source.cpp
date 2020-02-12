#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct pairs
{
	int x_coor;
	int y_coor;
};

int myfunction(pairs m, pairs n)
{
	return m.x_coor < n.x_coor;
}
double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int myfunction_cross(pairs m, pairs n)
{
	return m.y_coor < n.y_coor;
}

double minimal_distance_cross(double d, int x_mid, vector<long> x_ysort, vector<long> y_ysort)
{
	vector<pairs> points;
	for (int i = 0; i < x_ysort.size(); i++)
	{
		if (abs(x_ysort[i] - x_mid) < d)
			points.push_back({ x_ysort[i], y_ysort[i] });
	}
	//sort(points.begin(), points.end(), myfunction_cross);
	double d_cross = 10000000.0;
	for (int i = 0; i < points.size(); i++)
	{
		for (int j = i + 1; j < points.size() && (points[j].y_coor - points[i].y_coor < d_cross); j++)
		{
			if (d_cross > dist(points[i].x_coor, points[i].y_coor, points[j].x_coor, points[j].y_coor))
				d_cross = dist(points[i].x_coor, points[i].y_coor, points[j].x_coor, points[j].y_coor);
		}
	}
	return d_cross;
}

double minimal_distance_bruteforce(vector<long> x, vector<long> y)
{
	double d_m =  10000000.0;
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = i + 1; j < y.size(); j++)
		{
			double distance = dist(x[i], y[i], x[j], y[j]);
			if (distance < d_m)
				d_m = distance;
		}
	}
	return d_m;
}

double minimal_distance(vector<long> x, vector<long> y, vector<long> x_ysort, vector<long> y_ysort) {
	//write your code here
	if (x.size() <= 3)
		return minimal_distance_bruteforce(x, y);
	int mid = (x.size() - 1) / 2;
	long x_mid = x[mid];
	vector<long> x_left;
	vector<long> y_left;
	vector<long> x_right;
	vector<long> y_right;
	vector<long> x_left_ysort;
	vector<long> y_left_ysort;
	vector<long> x_right_ysort;
	vector<long> y_right_ysort;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] < x[mid])
		{
			x_left.push_back(x[i]);
			y_left.push_back(y[i]);
		}
		else if (x[i] > x[mid])
		{
			x_right.push_back(x[i]);
			y_right.push_back(y[i]);
		}
	}
	for (int i = 0; i < x_ysort.size(); i++)
	{
		if (x_ysort[i] < x[mid])
		{
			x_left_ysort.push_back(x_ysort[i]);
			y_left_ysort.push_back(y_ysort[i]);
		}
		else if (x_ysort[i] > x[mid])
		{
			x_right_ysort.push_back(x_ysort[i]);
			y_right_ysort.push_back(y_ysort[i]);
		}
	}
	double dl = minimal_distance(x_left, y_left, x_left_ysort, y_left_ysort);
	double dr = minimal_distance(x_right, y_right, x_right_ysort, y_right_ysort);
	double d = dl;
	if (dl > dr)
		d = dr;
	double d_cross = minimal_distance_cross(d, x_mid, x_ysort, y_ysort);
	if (d_cross < d)
		return d_cross;
	else
		return d;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<long> x(n);
	vector<long> y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	vector<pairs> points;
	vector<pairs> points_ysort;
	vector<long> x_ysort = x;
	vector<long> y_ysort = y;
	for (int i = 0; i < x.size(); i++)
	{
		points.push_back({ x[i], y[i] });
	}
	points_ysort = points;
	sort(points.begin(), points.end(), myfunction);
	sort(points_ysort.begin(), points_ysort.end(), myfunction_cross);
	for (int i = 0; i < x.size(); i++)
	{
		x[i] = points[i].x_coor;
		y[i] = points[i].y_coor;
	}
	for (int i = 0; i < x_ysort.size(); i++)
	{
		x_ysort[i] = points_ysort[i].x_coor;
		y_ysort[i] = points_ysort[i].y_coor;
	}
	/*for (auto v : x)
	{
		std::cout << v << " " << std::endl;
	}
	for (auto v : y)
	{
		std::cout << v << " " << std::endl;
	}
	for (auto v : x_ysort)
	{
		std::cout << v << " " << std::endl;
	}
	for (auto v : y_ysort)
	{
		std::cout << v << " " << std::endl;
	}*/
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << minimal_distance(x, y, x_ysort, y_ysort) << "\n";
	system("pause");
	return 0;
}
