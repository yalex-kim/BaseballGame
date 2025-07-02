#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& solution) : solution(solution) {
		assertIllegalArgument(solution);
		// Here we could store the solution if needed
	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		// Assuming the solution is "123" for demonstration purposes
		GuessResult result = {false, 0, 0};
		if (guessNumber == solution) {
			result.solved = true;
			result.strikes = 3; // All digits match
			return result;
		}
		for (size_t i = 0; i < guessNumber.length(); ++i) {
			if (guessNumber[i] == solution[i]) {
				result.strikes++;
			}
			else if (solution.find(guessNumber[i]) != string::npos) {
				result.balls++;
			}
		}
		return result;
	}
private:
	string solution;

	// Helper function to validate the input
	// Throws exceptions if the input is invalid

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