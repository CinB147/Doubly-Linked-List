#include <iostream>
#include <string>
#include <ctime>
#include "functions.h"

void print_list(Linked_list list);
Linked_list merge(Linked_list& l1, Linked_list& l2);
bool check(const Linked_list& list);


int main() {
	Linked_list list, list2, list3, list4;

	//----------------------TASK1-------------------------//
	std::cout << "-------------------------------TASK1--------------------------------" << std::endl;
	std::cout << "Task1 : Add two lists with 50 random numbers" << std::endl;
	
	for (int i = 0; i < 50; i++) {
		
		if (i == 0) {
			list.push_back(0);
			list2.push_back(0);
		}
		else {
			list.push_back(list.back() + rand() % 5);
			list2.push_back(list2.back() + rand() % 5);
		}
	}
	std::cout << "---list1---" << std::endl;
	list.print();
	std::cout << "List 1 size: " << list.size() << std::endl;
	std::cout << std::endl;
	std::cout << "---list2---" << std::endl;
	list2.print();
	std::cout << "List 2 size: " << list2.size()  << std::endl;
	std::cout << std::endl;
	//----------------------TASK2-------------------------//
	std::cout << "-------------------------------TASK2--------------------------------" << std::endl;
	std::cout << "Task2 : Finding element in 'n' position in the lists and compared the largest number." << std::endl; 
	std::cout << " The largest number must be removes, if the number is equal remove from any list " << std::endl;
	int n;
	std::cout << "Enter number of the element position 'n' in the list : ";
	std::cin >> n;
	std::cout << std::endl;

	double num1 = list.at(n);
	double num2 = list2.at(n);

	if (num1 > num2) {
		std::cout << num1 << " is greater then " << num2 << ", ";
		list.remove(n);
		std::cout << num1 << " from list1 has been removed" << std::endl;
		std::cout << "List 1 size: " << list.size() << std::endl;
	}
	if (num2 > num1) {
		std::cout << num2 << " is greater then " << num1 << ", ";
		list2.remove(n);
		std::cout << num2 << " from list2 has been removed" << std::endl;
		std::cout << "List 2 size: " << list2.size()  << std::endl;
	}
	if (num1 == num2) {
		int num;
		std::cout << " Choose list 1 or 2 :";
		std::cin >> num;
		if (num == 1) {
			list.remove(n);
			std::cout << num1 << " from list1 has been removed" << std::endl;
			std::cout << "List 1 size: " << list.size()  << std::endl;
		}
		if (num == 2) {
			list2.remove(n);
			std::cout << num2 << " from list2 has been removed" << std::endl;
			std::cout << "List 2 size: " << list2.size()  << std::endl;
		}
		std::cout << "---list1---" << std::endl;
		list.print();
		std::cout << "---list2---" << std::endl;
		list2.print();
	}
	std::cout << std::endl;
	//------------------------------TASK3----------------------------------//
	std::cout << "-------------------------------TASK3--------------------------------" << std::endl;
	std::cout << "Task 3 : Print the smallest list size in reverse. " << std::endl;

	if (list.size() > list2.size()) {
		list3 = list2;
		std::cout << "list3 contains : ";
		list3.print_reverse();

	}
	else {
		list3 = list;
		std::cout << "list3 contains : ";
		list3.print_reverse();

	}
	std::cout << std::endl;
	//-------------------------------TASK4--------------------------------//
	std::cout << "-------------------------------TASK4--------------------------------" << std::endl;
	std::cout << "Task 4 : Remove every other elemets on the list that contains 50 elements. " << std::endl;
	if (list.size() > list2.size()) {
		std::cout << "list 1 has 50 elements" <<std::endl;
		for (size_t i = 0; i < 25; i++) {
			list.pop_back();
			list.push_front(list.pop_back());
		}
		
		std::cout << "list 1 now has " << list.size() << " elements" << std::endl;
		list.print();
	}
	else {
		std::cout << "list 2 has 50 elements" << std::endl;
		for (size_t i = 0; i < 25; i++) {
			list2.pop_back();
			list2.push_front(list2.pop_back());
		}
		std::cout << "list 2 now has " << list2.size() << " elements" << std::endl;
		list2.print();
	}
	std::cout << std::endl;
	//-------------------------------TASK5--------------------------------//
	std::cout << "-------------------------------TASK5--------------------------------" << std::endl;
	std::cout << "Task 5 : Print the halved list using print_list funstions " << std::endl;
	std::cout << "List 1 size: " << list.size() << std::endl;
	std::cout << "List 2 size: " << list2.size() << std::endl;
	if (list.size() == 25) print_list(list);
	else print_list(list2);
	std::cout << std::endl;
	//------------------------------TASK6--------------------------------//
	std::cout << "-------------------------------TASK6--------------------------------" << std::endl;
	std::cout << "Task 6 : Merged list 1 and list 2. Create new list and put merge elements in newly list.  " << std::endl;
	list4 = merge(list, list2);
	list4.print();
	std::cout << std::endl;
	//-----------------------------TASK7--------------------------------//
	std::cout << "-------------------------------TASK7--------------------------------" << std::endl;
	std::cout << "Task 7 : Check if newly list in task6 is sorted.   " << std::endl;

	if (check(list4) == 1) {
		std::cout << "Newly list is sorted" << std::endl;
	}
	else {
		std::cout << "Newly list is NOT sorted" << std::endl;
	}

	return 0;
}

void print_list(Linked_list l) {
		l.print();
}

Linked_list merge(Linked_list& l1, Linked_list& l2) {
	Linked_list merge_list;

	while (!l1.is_empty() && !l2.is_empty()) { 
		if (l1.front() < l2.front()) {
			merge_list.push_back(l1.front());
			//std::cout << " list1 old " << l1.front() << " || ";
			l1.pop_front();
			//std::cout << " list1 new " << l1.front() << " || ";
		}
		else if (l2.front() < l1.front()) {
			merge_list.push_back(l2.front());
			//std::cout << " list2 old " << l2.front() << " || ";
			l2.pop_front();
			//std::cout << " list2 new " << l2.front() << " || ";
		}
		else if (l1.front() == l2.front()) {
			merge_list.push_back(l1.front());
			l1.pop_front();
			l2.pop_front();
		}

		
	}
	if (!l1.is_empty()) {
		merge_list += l1;
	}
	else if (!l2.is_empty()) {
		merge_list += l2;
	}
	return merge_list;
}

bool check(const Linked_list& list) {
	double num1, num2;
	for (size_t i = 0; i < list.size()-1; i++) { 
		num1 = list.at(i);
		num2 = list.at(i + 1);

		if (num2 < num1) {   
			return false;
		}
	}
	return true;

}