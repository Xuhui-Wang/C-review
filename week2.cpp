#include <iostream>

using namespace std;

template <class summable> // summable -- a generic type
summable sum(const summable data[], int size, summable s = 0)
{
	for (int i = 0; i < size; ++i)
		s += data[i];
	return s;
}

template <class T1, class T2>
void copy(const T1 source[], T2 destination[], int size)
{
	for (int i = 0; i < size; ++i) {
		destination[i] = static_cast<T2>(source[i]);
	}
}

typedef enum days {SUN, MON, TUE, WED, THU, FRI, SAT} days;
inline days operator++ (days d) {
	return static_cast<days>((static_cast<int>(d) + 1) % 7 );
}

ostream& operator<< (ostream& out, const days& d) {
	switch(d) {
		case SUN: out << "SUN"; break;
		case MON: out << "MON"; break;
		case TUE: out << "TUESDAY"; break;
		default: out << "NONE";
	}
}
class point {
public:
	double getx() { return x;}
	double gety() { return y;}
	void setx(double v) {x = v;}
	point(double x = 0.0, double y = 0.0) {
		this->x = x;
		this->y = y;
	}
private:
	double x, y;
};

point operator+ (point& p1, point& p2) {
	point sum = {p1.getx() + p2.getx(), p1.gety() + p2.gety()};
	return sum;
}
ostream& operator<< (ostream& out, point p) {
	out << "( " << p.getx() << ", " << p.gety() << " )";
	return out;
}
int main()
{
    cout << "template for sum()" << endl;
    int a[] = {1, 2, 3};
    double b[] = {2.1, 2.2, 2.3};
    cout << sum(a, 3) << endl;
    cout << sum(b, 3) << endl;
    days thisDay = SUN;
    for (int i = 0; i < 10; ++i)
		cout << ++thisDay;
	cout << endl;
	days d = MON, e;
	e = ++d;
	cout << d << '\t' << e << endl;
	cout << "test point operators: " << endl;
	point p1(3.5, 2.5), p2(2.5, 4.5), p3;
	point p4(2.3);
	cout << "p1 = " << p1 << " p2 = " << p2 << endl;
	cout << " sum = " << p1 + p2<< endl;
	cout << p4 << endl;
    return 0;
}
