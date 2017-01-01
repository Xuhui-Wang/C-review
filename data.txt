// simple vector program
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
	/*
    int how_many;
    cout << " How many ints in data?: " << endl;
    cin >> how_many;
    vector<int> data (how_many);
    cout << "The contents of data: ";
    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it)
		cin >> *it;
	cout << "Done input !!" << endl;
	*/
	ifstream data_file("data.txt");
	istream_iterator<int> start(data_file), end;
	vector<int> data(start, end);
	int sum = 0;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		sum += *it;
		cout << *it << "\t";
	}
	cout << endl;

	cout << "sum = " << sum << endl;
	cout << "average is = " << 1.0 * sum / data.size() << endl;
	cout << endl;
}
