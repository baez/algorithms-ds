#include <string>
#include <vector>

class Contact
{
public:
	virtual ~Contact() = 0;


	virtual std::string getName() const = 0;
	virtual void setName(const std::string& newName) = 0;
	virtual std::string getName2()
	{
		return name;
	}

protected:
	std::string id;
	std::string name;
	std::string phoneNumber;
	std::string address;
	std::string emailAddress;
	std::vector<Contact*> relatedContacts;
};