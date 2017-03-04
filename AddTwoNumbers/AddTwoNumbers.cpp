/**
 * @file	AddTwoNumbers.cpp.
 *
 * @brief	Implements the add two numbers class.
 */

/*******************************************************************************************
 *
 *
 *	You are given two linked lists representing two non-negative numbers.
 *	The digits are stored in reverse order and each of their nodes contain a single digit.
 *  Add the two numbers and return it as a linked list.
 *	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *	Output: 7 -> 0 -> 8
 *
 * *****************************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <list>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

/**
 * @fn	list<int> addTwoNumbers(list<int> lst1, list<int> lst2)
 *
 * @brief	Adds a two numbers to 'lst2'.
 *
 * @author	Zhang
 * @date	2017/3/4
 *
 * @param	lst1	The first list.
 * @param	lst2	The second list.
 *
 * @return	A list&lt;int&gt;
 */

list<int> addTwoNumbers(list<int> lst1, list<int> lst2)
{
	int num1 = 0;
	int num2 = 0;
	int totalNum = 0;
	int size1 = lst1.size();
	int size2 = lst2.size();
	int powNum = max(size1, size2);
	for (int i = 0; i < size1; i++)
	{
		num1 += lst1.front()*pow(10, i);
		lst1.pop_front();
	}
	for (int i = 0; i < size2; i++)
	{
		num2 += lst2.front()*pow(10, i);
		lst2.pop_front();
	}
	totalNum = num1 + num2;
	cout << "num1 = " << num1 << "; num2 = " << num2 << endl;

	if (totalNum > pow(10, powNum))
	{
		++powNum;
	}
	list<int> resultLst;
	for (int i = 0; i < powNum; i++)
	{
		resultLst.push_back(totalNum % 10);
		totalNum /= 10;
	}
	return resultLst;
}

int main()
{
	list<int> lst1;
	lst1.push_back(2);
	lst1.push_back(4);
	lst1.push_back(3);

	list<int> lst2;
	lst2.push_back(5);
	lst2.push_back(6);
	lst2.push_back(6);
	auto val = addTwoNumbers(lst1, lst2);
	//cout << "val = " << val << endl;
	return 0;
}

