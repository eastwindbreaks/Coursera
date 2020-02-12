#include <iostream>

int get_change(int m) {
	int a = m / 10;
	int b = (m - 10 * a) / 5;
	int c = m - 10 * a - 5 * b;
	return a + b + c;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
	system("pause");
	return 0;
}
