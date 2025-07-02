#include<gmock/gmock.h>
#include<string>
#include "baseball.cpp"

using std::string;

class BaseballGameTest : public ::testing::Test {
public:
	const string solution = "123";
	Baseball game{ solution };
	void assertIllegalArgument(const string& guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception& e) {

		}
	}
	void checkGuessResult(const GuessResult& expected, const GuessResult& actual) {
		EXPECT_EQ(expected.solved, actual.solved);
		EXPECT_EQ(expected.strikes, actual.strikes);
		EXPECT_EQ(expected.balls, actual.balls);
	}
};

TEST_F(BaseballGameTest, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballGameTest, ReturnSolvedResultIfMatchedNumber) {
	checkGuessResult({ true, 3, 0 }, game.guess(solution));
}

TEST_F(BaseballGameTest, ReturnZeroStrikesAndBallsIfNotMatched) {
	checkGuessResult({ false, 0, 0 }, game.guess("456"));
}

TEST_F(BaseballGameTest, ReturnStrikesAndBallsIfPartiallyMatched) {
	checkGuessResult({ false, 2, 0 }, game.guess("124"));
	checkGuessResult({ false, 1, 2 }, game.guess("132"));
	checkGuessResult({ false, 0, 2 }, game.guess("612"));
}


int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}