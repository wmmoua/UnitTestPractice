/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	
	/*protected:
		//PracticeTest(){} //constructor runs before each test
		//virtual ~PracticeTest(){} //destructor cleans up after tests
		//virtual void SetUp(){
		//} //sets up before each test (after constructor)
		//virtual void TearDown(){} //clean up after each test, (before destructor)
	*/
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("9Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, one_mixed_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Zz");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, no_upper_mixed_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZZ");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, no_lower_mixed_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zz");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zZ");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, SetValidPassword)
{
	Password my_password;
    my_password.set("NewPassword123");
    ASSERT_EQ(true, my_password.authenticate("NewPassword123"));
}

TEST(PasswordTest, SetInvalidShortPassword)
{
	Password my_password;
    my_password.set("123");
    ASSERT_EQ(false, my_password.authenticate("123"));
}

TEST(PasswordTest, SetInvalidLongPassword)
{
	Password my_password;
    std::string longPassword(21, 'a');
    my_password.set(longPassword);
    ASSERT_EQ(false, my_password.authenticate(longPassword));
}

TEST(PasswordTest, SetInvalidRepeatedLeadingCharacters)
{
	Password my_password;
    my_password.set("AAAABCD123");
    ASSERT_EQ(false, my_password.authenticate("AAAABCD123"));
}

TEST(PasswordTest, SetInvalidNoMixedCase)
{
	Password my_password;
    my_password.set("alllowercase");
    ASSERT_EQ(false, my_password.authenticate("alllowercase"));
}

TEST(PasswordTest, SetInvalidPreviouslyUsedPassword)
{
	Password my_password;
    my_password.set("NewPassword123");
    my_password.set("AnotherPassword456");
    my_password.set("NewPassword123");
    ASSERT_EQ(false, my_password.authenticate("NewPassword123"));
}

TEST(PasswordTest, AuthenticateCorrectPassword)
{
	Password my_password;
    my_password.set("Secret123");
    ASSERT_EQ(true, my_password.authenticate("Secret123"));
}

TEST(PasswordTest, AuthenticateIncorrectPassword)
{
	Password my_password;
    my_password.set("Secret123");
    ASSERT_EQ(false, my_password.authenticate("IncorrectPassword"));
}

TEST(PasswordTest, AuthenticateDefaultPassword)
{
	Password my_password;
	my_password = Password();
	ASSERT_EQ(true, my_password.authenticate("ChicoCA-95929"));
}

TEST(PasswordTest, AuthenticateNotDefaultPassword)
{
	Password my_password;
	my_password.set("NewPassword123");
	ASSERT_EQ(false, my_password.authenticate("ChicoCA-95929"));
}