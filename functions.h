#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <cstddef>
class Linked_list {
public:

	/*
		defualt constructor
	*/
	Linked_list(); 

	/// <summary>
	/// copy construct
	/// </summary>
	/// <param name="src"> reference values src in DLL</param>
	Linked_list(const Linked_list &src);

	/*
		deconstruct
	*/
	~Linked_list(); 

	/// <summary>
	/// assignment operator
	/// </summary>
	/// <param name="rhs"> reference rhs DLL </param>
	/// <returns> *this (pointing at...) value in list </returns>
	Linked_list& operator=(const Linked_list &rhs);

	/// <summary>
	/// assigment operator
	/// </summary>
	/// <param name="rhs"> reference rhs DLL </param>
	/// <returns> *this (pointing at...) value  </returns>
	Linked_list& operator+=(const Linked_list &rhs);

	void insert(size_t pos);

	/// <summary>
	/// Putting values in front of DDL
	/// </summary>
	/// <param name="value"> input value which will be push back in DLL </param>
	void push_front(double value);

	/// <summary>
	/// Putting values in back of DDL
	/// </summary>
	/// <param name="value"> input value which will be push back in CLL </param>
	void push_back(double value);

	/// <summary>
	/// Accessing from front
	/// </summary>
	/// <returns> pointers values</returns>
	double front() const;

	/// <summary>
	/// Accessing from back
	/// </summary>
	/// <returns> pointers values</returns>
	double back() const;

	/// <summary>
	/// accessing values by posisioning
	/// </summary>
	/// <param name="pos">  input position of list 'array' in DLL</param>
	/// <returns>it* values</returns>
	double at(size_t pos) const;

	/// <summary>
	/// remove elememnt form DDL by positioning
	/// </summary>
	/// <param name="pos"> position in 'array' of DLL</param>
	void remove(size_t pos);

	/// <summary>
	/// remove elements in front (first elements of DLL will be removed)
	/// </summary>
	/// <returns> DLL values</returns>
	double pop_front();

	/// <summary>
	/// remove elements in back (last elements of DLL will be removed)
	/// </summary>
	/// <returns> DLL values</returns>
	double pop_back();

	/// <summary>
	/// count size of DLL
	/// </summary>
	/// <returns> size count </returns>
	size_t size() const;

	/// <summary>
	/// Determined if DLL head and tail is empty (NULL)
	/// </summary>
	/// <returns> true or false </returns>
	bool is_empty() const;

	
	/// <summary>
	///  accessing head of DLL,if head pointer isn't pointing at null: print values and goes to next node. 
	/// </summary>
	void print() const;

	/// <summary>
	///  accessing tail of DLL, if tail pointer isn't pointing at null: print values and goes to prev node.
	/// </summary>
	void print_reverse() const;


private:
	struct node {
		node(double value);
		double value;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;

};

#endif

