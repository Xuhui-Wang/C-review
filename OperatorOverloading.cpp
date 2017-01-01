#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

enum color {RED, BLUE, GREEN};

ostream& operator<<(ostream& out, color c)
{
	switch(c) {
	case RED:
		out << "(" << "color red";
		break;
	default:
		out << "(" << "other" << ")";
		break;
	}
	return out;
}

class point
{
public:
	point(): x(0.0), y(0.0) {}
	point(double u): x(u), y(0.0) {}
	point(double x, double y): x(x), y(y) {}
	operator double() {return sqrt(x * x + y * y); }
private:
	double x, y;
};

//// overload the << operator on "point" class
//ostream& operator<<(ostream& out, const point& p)
//{
//	out << "(" << p.x << ", "<< p.y << ")";
//	return out;
//}
int main()
{
    color c = RED;
    cout << c << endl;

    point s;
    double d = 3.5;
    s = d;
    point s1(3, 4);
    double dd = s1;
    cout <<dd << endl;

	vector<int> v(100);
	for (int i = 0; i < 100; ++i)
		v[i] = i;            // index thru like an array
    for (vector<int>::iterator p = v.begin(); p != v.end(); ++p)
		cout << *p << '\t';
	cout << endl;
	for (auto p = v.begin(); p != v.end(); ++p)
		cout << *p << '\t';
	cout << endl;
	int arr[100];
	arr[0] = 3;
	arr[1] = 10;
	cout << *(arr + 1) << endl;
    return 0;
}
