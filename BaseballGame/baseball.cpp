#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& input) {
		if (input.length() != 3) {
			throw length_error("Input must be exactly 3 characters long.");
		}
	}
};