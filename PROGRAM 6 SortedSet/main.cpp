#include "SortedSet.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Enter a test number(1-9): ";
	int test;
	cin >> test;
	cout << endl;
    //tests constructor, destructor, push_front, pop_front, display
    if (test == 1) {
        cout << endl;
        cout << "list1 constructor called" << endl;
        IntList list1;
        cout << "pushfront 10" << endl;
        list1.push_front(10);
        cout << "pushfront 20" << endl;
        list1.push_front(20);
        cout << "pushfront 30" << endl;
        list1.push_front(30);
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
    }
    if (test == 1) {
        cout << "list1 destructor called" << endl;
    }

    //tests push_back
    if (test == 2) {
        cout << endl;
        cout << "list2 constructor called" << endl;
        IntList list2;
        cout << "pushback 10" << endl;
        list2.push_back(10);
        cout << "pushback 20" << endl;
        list2.push_back(20);
        cout << "pushback 30" << endl;
        list2.push_back(30);
        cout << "list2: " << list2 << endl;
        cout << "pop" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
        cout << "pop" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
        cout << "pop" << endl;
        list2.pop_front();
        cout << "list2: " << list2 << endl;
    }
    if (test == 2) {
        cout << "list2 destructor called" << endl;
    }

    //tests selection_sort
    if (test == 3) {
        cout << endl;
        cout << "list3 constructor called" << endl;
        IntList list3;
        cout << "pushfront 10" << endl;
        list3.push_front(10);
        cout << "pushfront 20" << endl;
        list3.push_front(20);
        cout << "pushfront 30" << endl;
        list3.push_front(30);
        cout << "list3: " << list3 << endl;
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
        cout << "pop" << endl;
        list3.pop_front();
        cout << "pop" << endl;
        list3.pop_front();
        cout << "pop" << endl;
        list3.pop_front();
        cout << "list3: " << list3 << endl;
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
        cout << "pushfront 10" << endl;
        list3.push_front(10);
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
        cout << "pushfront 20" << endl;
        list3.push_front(20);
        cout << "list3: " << list3 << endl;
        cout << "selection_sort()" << endl;
        list3.selection_sort();
        cout << "list3: " << list3 << endl;
    }
    if (test == 3) {
        cout << "list3 destructor called" << endl;
    }

    //tests insert_sorted
    if (test == 4) {
        cout << endl;
        cout << "list4 constructor called" << endl;
        IntList list4;
        cout << "insert 20" << endl;
        list4.insert_ordered(20);
        cout << "insert 10" << endl;
        list4.insert_ordered(10);
        cout << "insert 30" << endl;
        list4.insert_ordered(30);
        cout << "list4: " << list4 << endl;
        cout << "insert 50" << endl;
        list4.insert_ordered(50);
        cout << "list4: " << list4 << endl;
        cout << "insert 40" << endl;
        list4.insert_ordered(40);
        cout << "list4: " << list4 << endl;
        cout << "insert 11" << endl;
        list4.insert_ordered(11);
        cout << "list4: " << list4 << endl;
        cout << "insert 10" << endl;
        list4.insert_ordered(10);
        cout << "list4: " << list4 << endl;
        cout << "insert 11" << endl;
        list4.insert_ordered(11);
        cout << "list4: " << list4 << endl;
        cout << "insert 9" << endl;
        list4.insert_ordered(9);
        cout << "list4: " << list4 << endl;
        cout << "insert 50" << endl;
        list4.insert_ordered(50);
        cout << "list4: " << list4 << endl;
        cout << "insert 51" << endl;
        list4.insert_ordered(51);
        cout << "list4: " << list4 << endl;
    }
    if (test == 4) {
        cout << "list4 destructor called" << endl;
    }

    //tests remove_duplicates
    if (test == 5) {
        cout << endl;
        cout << "list5 constructor called" << endl;
        IntList list5;
        cout << "pushfront 10" << endl;
        list5.push_front(10);
        cout << "pushfront 20" << endl;
        list5.push_front(20);
        cout << "pushfront 10" << endl;
        list5.push_front(10);
        cout << "pushfront 30" << endl;
        list5.push_front(30);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "pushfront 10" << endl;
        list5.push_front(10);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "pushfront 20" << endl;
        list5.push_front(20);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "pushfront 20" << endl;
        list5.push_front(20);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "pushfront 20" << endl;
        list5.push_front(20);
        cout << "pushfront 20" << endl;
        list5.push_front(20);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "pop" << endl;
        list5.pop_front();
        cout << "pop" << endl;
        list5.pop_front();
        cout << "push_front(30)" << endl;
        list5.push_front(30);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "push_front(30)" << endl;
        list5.push_front(30);
        cout << "push_front(30)" << endl;
        list5.push_front(30);
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
        cout << "pop" << endl;
        list5.pop_front();
        cout << "list5: " << list5 << endl;
        cout << "remove_duplicates()" << endl;
        list5.remove_duplicates();
        cout << "list5: " << list5 << endl;
    }
    if (test == 5) {
        cout << "list5 destructor called" << endl;
    }

    /*
    * Destructor will be tested by looking at code. There is no run-time 
    * test for it. Make sure your destructor actually deletes ALL nodes, not
    * just the head and/or tail.
    */

    //tests constructor, destructor
    if (test == 6) {
        cout << endl;
        cout << "set1 constructor called" << endl;
        SortedSet set1;
    }
    if (test == 6) {
        cout << "set1 destructor called" << endl;
    }

    //tests copy constructor, in
    if (test == 7) {
        cout << endl;
        IntList list2;
        list2.push_back(10);
        list2.push_back(30);
        list2.push_back(50);
        list2.push_back(40);
        list2.push_back(20);
        list2.push_back(50);
        cout << "set2 copy constructor called" << endl;
        SortedSet set2(list2);
        cout << "set2: " << set2 << endl;
        if (set2.in(30)) {
            cout << "30 found in set2" << endl;
        } else {
            cout << "ERROR: 30 should be in set2" << endl;
        }
        if (set2.in(60)) {
            cout << "ERROR: 60 found in set2" << endl;
        } else {
            cout << "60 not found in set2" << endl;
        }
        if (set2.in(0)) {
            cout << "ERROR: 0 found in set2" << endl;
        } else {
            cout << "0 not found in set2" << endl;
        }
    }
    if (test == 7) {
        cout << "list2 destructor called" << endl;
    }

    //tests add, push_front, push_back, insert_ordered
    if (test == 8) {
        cout << endl;
        cout << "set3 constructor called" << endl;
        SortedSet set3;
        cout << "pushfront 10" << endl;
        set3.push_front(10);
        cout << "pushfront 20" << endl;
        set3.push_front(20);
        cout << "pushback 40" << endl;
        set3.push_back(40);
        cout << "pushback 30" << endl;
        set3.push_back(30);
        cout << "insert 20" << endl;
        set3.insert_ordered(20);
        cout << "set3: " << set3 << endl;
    }
    if (test == 8) {
        cout << "set3 destructor called" << endl;
    }

    //tests union operator|, intersection operator&
    if (test == 9) {
        cout << endl;
        cout << "set4 constructor called" << endl;
        SortedSet set4;
        set4.push_back(40);
        set4.push_back(20);
        set4.push_back(10);
        cout << "set4: " << set4 << endl;
        cout << "set5 constructor called" << endl;
        SortedSet set5;
        set5.push_back(50);
        set5.push_back(30);
        set5.push_back(10);
        cout << "set5: " << set5 << endl;
        cout << "set6 constructor called" << endl;
        SortedSet set6 = set4 | set5;
        cout << "set4 | set5 = set6: " << set6 << endl;
        cout << "set7 constructor called" << endl;
        SortedSet set7 = set4 & set5;
        cout << "set4 & set5 = set7: " << set7 << endl;
        cout << "set7 | set6" << endl;
        set7 |= set6;
        cout << "set7: " << set7 << endl;
        cout << "set4 & set5" << endl;
        set4 &= set5;
        cout << "set4: " << set4 << endl;
    }
    if (test == 9) {
        cout << "list2 destructor called" << endl;
    }

    return 0;
}
