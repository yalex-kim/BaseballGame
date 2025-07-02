#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& input) {
		if (input.length() != 3) {
			throw length_error("Input must be exactly 3 characters long.");
		}
		if(input.find_first_not_of("0123456789") != string::npos) {
			throw invalid_argument("Input must only contain digits.");
		}
	}
};