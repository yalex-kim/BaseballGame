#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Input must be exactly 3 characters long.");
		}
		if (guessNumber.find_first_not_of("0123456789") != string::npos) {
			throw invalid_argument("Input must only contain digits.");
		}
		if (IsDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Digits must be unique.");
		}
	}
	bool IsDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}
};