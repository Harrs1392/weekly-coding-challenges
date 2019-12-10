#include <list>
#include <string>


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
