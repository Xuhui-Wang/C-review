#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <time.h>
#include <stdlib.h>
#include <random>
using namespace std;

template<typename T> void print_queue(T& q) {
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}

class list_element {
public:
	list_element(int n = 0, list_element* ptr = 0):
		d(n), next(ptr) {}
	int d;
	list_element* next;
};

class list {
public:
	list(): head(0), cursor(0) {}
	list(const list& lst) {
        if (lst.head == 0) {
			head = 0;
			cursor = 0;
        } else {
			cursor = lst.head;
			list_element* h = new list_element();
			list_element* previous;
			head = h;
			h->d = lst.head->d;
			previous = h;
			for (cursor = lst.head; cursor != 0; ) {
			{
				{
					h = new list_element();
					h->d = cursor->d;
					previous->next = h;
					cursor = cursor->next;
					previous = h;
				}
				cursor = head;
			}
        }
        }

	}
	~list()
	{
		for (cursor = head; cursor != 0; )
		{
			cursor = head->next;
			delete head;
			head = cursor;
		}
	}
	void prepend(int n) {
		if (head == 0)
			cursor = head = new list_element(n, head);
		else
			head = new list_element(n, head);
	}
	int get_element() {return cursor -> d;}
	void advance() {cursor = cursor->next;}
	void print() {
		list_element* h = head;
        while (h != 0) {
			cout << h->d << ", ";
			h = h->next;
        }
        cout << "###" << endl;
	}
private:
	list_element* head;
	list_element* cursor;
};


int main()
{
	/*
	int size = 9;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n : {1, 8, 5, 6, 2, 3})
		pq.push(n);
	cout << pq.size() << endl;
    print_queue(pq);
    */

	//use of new / delete
//	char* s = new char[size];  // get off the heap
//    int* p = new int(9);    // single int initialized
//    delete [] s;
//    delete p;
/*
    bool** graph;
    srand(time(0));
    graph = new bool*[size];
    for (int i = 0; i < size; ++i)
		graph[i] = new bool[size];
    for (int i = 0; i < size; ++i)
		for (int j = i; j < size; ++j)
		{
			if(i == j)
				graph[i][j] = false;
			else
				graph[i][j] = graph[j][i] = ((double) rand() / (RAND_MAX));

		}
*/
/*
	list a, b;
	a.prepend(9);
	a.prepend(8);
	a.print();
	for (int i = 0; i < 40; ++i)
		b.prepend(i * i);
    cout << " list b " << endl;
    b.print();
  */
    list a, b;
    int data[10] = {3, 4, 6, 7, -3, 5};
    list d(data, 6);
    list e(data, 10);
    return 0;
}

