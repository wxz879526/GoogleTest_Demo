// GoogleTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "gtest/gtest.h"

int Foo(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw "don't do this";
	}

	int c = a%b;
	if (c == 0) 
	{
		return b;
	}

	return Foo(b, c);
}

int Add(int a, int b)
{
	return a + b;
}

TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
}

TEST(AddTest, HandleNoneZeroInput1)
{
	EXPECT_EQ(4, Add(1, 2)) << "Add Failed";
}

class FooEnviroment : public testing::Environment {
public:
	virtual void SetUp() override { std::cout << "env setup" << std::endl; }
	virtual void TearDown() override { std::cout << "env Teardown" << std::endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	testing::AddGlobalTestEnvironment(new FooEnviroment());
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();

	return 0;
}

