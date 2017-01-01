// use accumulate function
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int data[4] = {1, 2, 3, 4};
    cout << accumulate(data, data + 4, 5);
}
