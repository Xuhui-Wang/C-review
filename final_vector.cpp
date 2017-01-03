//self add/subtract don't apply to iterators;

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main()

{

	vector<int> data(20,1);

	int sum {0};

	cout << sum << endl;

	for(auto element : data)

		sum += element;

	cout << sum << endl;
//	cout << "begin: " << *data.begin() << endl;
//	cout << "end: " << *data.end() << endl;

	for(auto p = ++data.begin(); p != --data.end(); ++p)
	{
//		cout << "begin - 5: " << *(data.begin() - 5) << " end - 5: " << *(data.end() - 5) << endl;
//        cout << "begin - 4: " << *(data.begin() - 4) << " end - 4: " << *(data.end() - 4) << endl;
//        cout << "begin - 3: " << *(data.begin() - 3) << " end - 3: " << *(data.end() - 3) << endl;
//        cout << "begin - 2: " << *(data.begin() - 2) << " end - 2: " << *(data.end() - 2) << endl;
//        cout << "begin - 1: " << *(data.begin() - 1) << " end - 1: " << *(data.end() - 1) << endl;
//        cout << "begin: " << *data.begin() << " end : " << *data.end() << " p: " << *p << endl;
//        cout << "begin + 1: " << *(data.begin() + 1) << " end + 1: " << *(data.end() + 1) << endl;
//        cout << "begin + 2: " << *(data.begin() + 2) << " end + 2: " << *(data.end() + 2) << endl;
//        cout << "begin + 3: " << *(data.begin() + 3) << " end + 3: " << *(data.end() + 3) << endl;
//        cout << "begin + 4: " << *(data.begin() + 4) << " end + 4: " << *(data.end() + 4) << endl;
//        cout << "begin + 5: " << *(data.begin() + 5) << " end + 5: " << *(data.end() + 5) << endl;
		sum += *p;
	}

	cout << sum << endl;

	sum = 0;

	data.push_back(2);

	data.push_back(3);

	for(auto element : data)

		sum += element;

	cout << sum << endl;

	cout << accumulate(data.begin(), data.end(), data[0]) << endl;
}
