#include<gmock/gmock.h>
#include<string>
#include "baseball.cpp"

using std::string;

class BaseballGameTest : public ::testing::Test {
public:
	Baseball game;
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


int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}