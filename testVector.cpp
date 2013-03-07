/* 
 * File:   main.cpp
 * Author: Abhishek Deshpande
 *
 * Created on January 30, 2011, 12:18 PM
 */

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include "Vector.h"

using namespace std;
using namespace cop4530;

main() {
    typedef Vector<int>::iterator ITRINT;
    typedef Vector<string>::iterator ITRSTR;
    Vector<int> v1;
    ITRINT itr;
    Vector<string> v2;
    ITRSTR itr2;
    const int num = 10;

    cout << "Testing vector with integer values ..." << endl;
    cout << "Pushing back " << num << " integer values" << endl;

    // add elements
    for (int i = 0; i < num; ++i) {
  v1.push_back(i);
    }
    cout << "Size = " << v1.size() << " Capacity = " << v1.capacity() << endl;

    // output all elements
    itr = v1.begin();
    cout << *itr++;
    for (; itr != v1.end(); ++itr) {
	cout << " " << *itr;
    }
    cout << endl;

    // using copy algorithm to print out elements.
    // note the use of ostream_iterator
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Pop back " << num/2 << " integer values" << endl;
    for (int i = 0; i < num/2; ++i) {
	v1.pop_back();
    }

    cout << "Size = " << v1.size() << " Capacity = " << v1.capacity() << endl;

    itr = v1.begin();
    cout << *itr++;
    for (; itr != v1.end(); ++itr) {
	cout << " " << *itr;
    }
    cout << endl;

    cout << "Removing first 4 elements" << endl;
    itr = v1.begin();
    ITRINT itr_t = itr;
    for (int i = 0; i < 4; ++i)
	++itr_t;
    v1.erase(itr, itr_t);
    cout << "Size = " << v1.size() << " Capacity = " << v1.capacity() << endl;

    // output using the overloaded output operator.
    cout << v1 << endl;

    cout << "Testing resize" << endl;
    Vector<int> v_t11(8, 2);
    v_t11.resize(3);

    cout << v_t11 << endl;
    v_t11.resize(5);
    cout << v_t11 << endl;

    cout << "Testing push_front" << endl;
    Vector<int> v_t10(8, 5);
    v_t10.push_front(10);
    cout << v_t10 << endl;

    cout << "Clearing list" << endl;
    v1.clear();

    if (v1.empty()) {
	cout << "All cleared" << endl;
    } else {
	cout << "WRONG: clear() function" << endl;
    }

    cout << "Testing other constructors" << endl;
    Vector<int> v_t1(8, 2);
    Vector<int> v_t2(v_t1.begin(), v_t1.end()-v_t1.begin());

    cout << v_t2 << endl;


    cout << "Testing comparison operators" << endl;
    if (v_t1 == v_t2) {
	cout << "They are the same" << endl;
    } else {
	cout << "WRONG: comparison operator or constructors" << endl;
    }

    cout << "Remove one element from v_t1" << endl;
    v_t1.pop_back();
    if (v_t1 == v_t2) {
	cout << "WRONG: pop_back()" << endl;
    } else {
	cout << "They contain different values" << endl;
    }

    /* testing string list */
    cout << "Testing vector with string values ..." << endl;
    cout << "Pushing back " << num << " string values" << endl;

        for (int i = 1; i <= num; ++i) {
	string str(i, '0');
	v2.push_back(str);
    }
    cout << "Size = " << v2.size() << " Capacity = " << v2.capacity() << endl;

    itr2 = v2.begin();
    cout << *itr2++;
    for (; itr2 != v2.end(); ++itr2) {
	cout << " " << *itr2;
    }
    cout << endl;

    copy(v2.begin(), v2.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << "Pop back " << num/2 << " string values" << endl;
    for (int i = 0; i < num/2; ++i) {
	v2.pop_back();
    }
    cout << "Size = " << v2.size() << " Capacity = " << v2.capacity() << endl;

    itr2 = v2.begin();
    cout << *itr2++;
    for (; itr2 != v2.end(); ++itr2) {
	cout << " " << *itr2;
    }
    cout << endl;

    cout << "Removing first 4 elements" << endl;
    itr2 = v2.begin(); 
    ITRSTR itr2_t = itr2;
    for (int i = 0; i < 4; ++i)
	++itr2_t;
    v2.erase(itr2, itr2_t);
    cout << "Size = " << v2.size() << " Capacity = " << v2.capacity() << endl;

    // output using the overloaded output operator
    cout << v2 << endl;

    cout << "Clearing vector" << endl;
    v2.clear();

    if (v2.empty()) {
	cout << "All cleared" << endl;
    } else {
	cout << "WRONG: clear() function" << endl;
    }

    cout << "Testing other constructors" << endl;
    Vector<string> v2_t1(8, "2");
    Vector<string> v2_t2(v2_t1.begin(), v2_t1.end()-v2_t1.begin());

    cout << v2_t2 << endl;

    cout << "Testing comparison operators" << endl;
    if (v2_t1 == v2_t2) {
	cout << "They are the same" << endl;
    } else {
	cout << "WRONG: comparison operator or constructors" << endl;
    }

    cout << "Remove one element from v2_t1" << endl;
    v2_t1.pop_back();
    if (v2_t1 == v2_t2) {
	cout << "WRONG: pop_back()" << endl;
    } else {
	cout << "They contain different values" << endl;
    }

   
}
