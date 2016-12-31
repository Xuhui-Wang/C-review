#include <iostream>

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
int main()
{
    color c = RED;
    cout << c << endl;
    return 0;
}
