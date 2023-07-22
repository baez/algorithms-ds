#include "Contact.h"

class Person : public Contact
{
	virtual std::string getName2()
	{
		return name + " - ";
	}
};