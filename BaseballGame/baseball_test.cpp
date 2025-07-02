#include<gmock/gmock.h>
#include<string>
#include "baseball.cpp"

using std::string;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(
		game.guess(string("12")),
		length_error
	);
}


int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}