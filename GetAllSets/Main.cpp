#include <string>
#include <iostream>
#include <list>
/*
	Return all the sets of a list of numbers
*/

void iterateThroughList(std::list<int>& list_of_items, std::list<int>::iterator& iter, int desired_size, std::list<std::list<int>>* out ) {
	std::list<int> output;
	std::list<int>::iterator next_iter = next(iter);
	for (int i = 0; i < desired_size; ++i) {
		output.push_back(*iter);
		iter++;
	}
	out->push_back(output);
	if (iter == list_of_items.end());
	else iterateThroughList(list_of_items, next_iter, desired_size, out);
}
void outputSetBySize(std::list<int>& list_of_items, int desired_size, std::list<std::list<int>>* out) {
	std::list<int>::iterator iter = list_of_items.begin();
	iterateThroughList(list_of_items, iter, desired_size, out);
	if (list_of_items.size() == desired_size);
	else outputSetBySize(list_of_items, ++desired_size, out);
}
int main() {
	std::list<int> lst;
	for (int i = 1; i <= 10; ++i) lst.push_back(i);
	std::list<std::list<int>> return_value;
	outputSetBySize(lst, 1 , &return_value);
}