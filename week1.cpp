#include <iostream>
#include <complex>
using namespace std;

template<class T>
inline void swapClass(T& d, T& s)  // swap() has already been implemented
{
	T temp = d;
	d = s;
	s = temp;
}

int main()
{
    int m = 5, n = 10;
    double x = 5.3, y = 10.6;
    complex<double> r(2.4, 3.6), s(3.4, 6.7);
    cout << "input: " << m << ", " << n << endl;
    swap(m, n);
    cout << "outputs: " << m << ", " << n << endl;
    cout << "double input: " << x << ", " << y << endl;
    swap(x, y);
    cout << "outputs: " << x << ", " << y << endl;
    cout << "double input: " << r << ", " << s << endl;
    swap(r, s);
    cout << "outputs: " << r << ", " << s << endl;
    return 0;
}
