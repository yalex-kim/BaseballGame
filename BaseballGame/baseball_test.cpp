#include<gmock/gmock.h>
#include<string>
#include "baseball.cpp"

using std::string;

class BaseballGameTest : public ::testing::Test {
public:
	Baseball game{"123"};
	void assertIllegalArgument(const string& guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception& e) {

		}
	}
};

TEST_F(BaseballGameTest, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballGameTest, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}


int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}