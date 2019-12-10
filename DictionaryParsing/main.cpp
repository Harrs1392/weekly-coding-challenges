#include <string>
#include <list>
#include <map>
#include "LocationHolder.cpp"

/* 
	Find the words in the sentance from the dictionary and make a list out of them. to make the whole sentance (if you cant return null)
*/

int main() {

}


std::list<std::string> makeArray(std::map<std::string, std::string> &dictionary, std::string &sentance) {

	char* iter = const_cast<char *>(sentance.c_str());
	std::list<LocationHolder> list_locations = std::list<LocationHolder>();
	std::list<std::string> list_of_words;
	std::string dictionary_return;
	std::string current_word= "";
	while(true) {
		current_word += iter;
		dictionary_return = dictionary[current_word];
		++iter;
		if (dictionary_return != "") {
			list_of_words.push_back(dictionary_return);
			list_locations.push_back(LocationHolder(iter));
		}
	}

	/* not done */
}