
class LocationHolder {
public:
	char* start_of_word;
	int amount_of_words_tried = 0;
	int amount_of_words_passed = 0;

	LocationHolder(char* start) {
		start_of_word = start;
	}
};