#include <iostream>
#include "DataObject.h"

int main()
{
	DataObject object("rich");
	std::cout << "expect rich actual " << object << std::endl;

	DataObject object2(std::string("Rich"));
	std::cout << "expect Rich actual " << object2 << std::endl;

	object["Guid"] = "1234";
	std::cout << "expect 1234 actual " << object["Guid"] << std::endl;
	
	std::cout << "expect actual " << object["socketid"] << std::endl;

	// object["Guid"]["Manageability"] = "True";

	// std::cout << object << std::endl;
}
