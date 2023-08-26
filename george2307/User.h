#pragma once


class User
{
private:
	int age;
	int level;

public:
	User() : age(25), level(1)
	{
		std::cout << "User Def. Contructed" << std::endl;
	}

	User(int age, int level) : age(age), level(level)
	{
		std::cout << "User Contructed" << std::endl;
	}

	~User()
	{
		std::cout << "User Destructed" << std::endl;
	}

};