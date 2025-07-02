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
	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		initResult();
		countStrike(guessNumber);
		countBall(guessNumber);
		updateResolve();

		return result;
	}

	void initResult()
	{
		result = { false, 0, 0 };
	}

	void updateResolve()
	{
		result.solved = (result.strikes == 3);
	}
	void countBall(const std::string& guessNumber)
	{
		for (size_t i = 0; i < guessNumber.length(); ++i) {
			if (guessNumber[i] != solution[i] && solution.find(guessNumber[i]) != string::npos) {
				result.balls++;
			}
		}
	}
	void countStrike(const std::string& guessNumber)
	{
		for (size_t i = 0; i < guessNumber.length(); ++i) {
			if (guessNumber[i] == solution[i]) {
				result.strikes++;
			}
		}
	}
private:
	string solution;
	GuessResult result = { false, 0, 0 };

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