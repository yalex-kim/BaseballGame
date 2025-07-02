#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Input must be exactly 3 characters long.");
		}
		if(guessNumber.find_first_not_of("0123456789") != string::npos) {
			throw invalid_argument("Input must only contain digits.");
		}
		if(guessNumber[0] == guessNumber[1] || 
		   guessNumber[0] == guessNumber[2] || 
		   guessNumber[1] == guessNumber[2]) {
			throw domain_error("Digits must be unique.");
		}
	}
};