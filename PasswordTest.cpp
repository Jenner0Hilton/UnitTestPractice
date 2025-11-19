/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, six_z_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZZ");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, upper_and_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zH");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, only_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("zxy");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, only_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("HXMLP");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, lower_and_space)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("a ");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, upper_and_space)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("H ");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, upper_followed_by_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Habcd");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, fully_unique_string)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("abc");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, semi_unique_string)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("abb");
	ASSERT_EQ(2,actual);
}