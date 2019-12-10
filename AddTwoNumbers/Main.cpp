#include <list>
#include <string>

/*
	LeetCode.com
	Question #2: Add Two Numbers

	You are given two non-empty linked lists representing two non-negative integers.
	The digits are stored in reverse order and each of their nodes contain a single digit.
	Add the two numbers and return it as a linked list.
	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example:

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807.
*/


std::list<unsigned> getProductReversed(std::list<unsigned>& first, std::list<unsigned>& second) {
	std::list<unsigned> returnArray;
	unsigned firstNumber = 0;
	unsigned secondNumber = 0;
	unsigned returnNumber = 0;
	std::list<unsigned>::iterator iter = first.end();
	--iter;
	for (; iter != first.begin(); --iter)
		firstNumber = firstNumber * 10 + *iter;
	firstNumber = firstNumber * 10 + *iter;
	iter = second.end();
	--iter;
	for (; iter != second.begin(); --iter)
		secondNumber = secondNumber * 10 + *iter;
	secondNumber = secondNumber * 10 + *iter;
	returnNumber = firstNumber + secondNumber;
	std::string returnNumberString = std::to_string(returnNumber);
	for (int i = 0; i < returnNumberString.length(); ++i) {
		returnArray.push_front(returnNumberString[i] - '0');
	}
	return returnArray;
}
int main() {
	std::list<unsigned> first{ 5,9,3 };
	std::list<unsigned> second{ 3,2,1 };
	std::list<unsigned> returnArray = getProductReversed(first, second);
}