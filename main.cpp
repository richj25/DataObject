#include <iostream>
#include "DataObject.h"

int main()
{
	std::cout << "DataObject tests" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	std::cout << "Initialize with const char*" << std::endl;
	DataObject object1("rich");
	std::cout << "expect rich actual " << object1 << std::endl;
	std::cout << std::endl;

	std::cout << "Initialize with std::string" << std::endl;
	DataObject object2(std::string("Rich"));
	std::cout << "expect Rich actual " << object2 << std::endl;
	std::cout << std::endl;

	std::cout << "Initialize no parameters" << std::endl;
	DataObject object3;
	std::cout << "expect  actual " << object3 << std::endl;
	std::cout << std::endl;

	std::cout << "Assign with const char*" << std::endl;
	object1 = "Sammy";
	std::cout << "expect  Sammy actual " << object1 << std::endl;
	std::cout << std::endl;
	
	std::cout << "Assign with std::string" << std::endl;
	object1 = std::string("Sammy");
	std::cout << "expect  Sammy actual " << object1 << std::endl;
	std::cout << std::endl;

	std::cout << "One level array index" << std::endl;	
	object1["Guid"] = "1234";
	std::cout << "expect 1234 actual " << object1["Guid"] << std::endl;
	std::cout << std::endl;

	std::cout << "Non-existent attribute returns empty object" << std::endl;	
	std::cout << "expect actual " << object1["socketid"] << std::endl;
	std::cout << std::endl;

	std::cout << "Two level array index" << std::endl;	
	object1["Guid"]["Manageability"] = "True";
	std::cout << "expect True actual " << object1["Guid"]["Manageability"] << std::endl;
	std::cout << std::endl;

	std::cout << "Four level array index" << std::endl;	
	object1["1"]["2"]["3"]["4"] = "5";
	std::cout << "expect 5 actual " << object1["1"]["2"]["3"]["4"] << std::endl;;
	std::cout << std::endl;

	std::cout << "Dogs are better than cats, right?" << std::endl;	
	object1 = "dogs";
	object2 = "cats";
	std::cout << "Yes, " << (object1 > object2 ? object1 : object2) << " are better than ";
	std::cout << (object1 < object2 ? object1 : object2) << std::endl;
	std::cout << std::endl;

	std::cout << "Assign one object to another" << std::endl;	
	object2 = object1;	
	std::cout << "expect 5 actual " << object2["1"]["2"]["3"]["4"] << std::endl;;
	std::cout << std::endl;

	std::cout << "Test dump" << std::endl;
	object2.dump();
	std::cout << std::endl;

	ProviderObject provider;
	std::cout << "ProviderObject tests" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	std::cout << "One Level fetch command, data is present" << std::endl;
	provider["Guid"] = "1234";
	std::cout << "expect 1234 actual " << provider["Guid"] << std::endl;	
	std::cout << std::endl;

	std::cout << "One Level fetch command, data is not present" << std::endl;
	std::cout << "expect fetching socketId actual " << provider["socketId"] << std::endl;	
	std::cout << std::endl;

	std::cout << "Two Level fetch command, data is present" << std::endl;
	provider["Guid"]["socketId"] = "2";
	std::cout << "expect 2 actual " << provider["Guid"]["socketId"] << std::endl;	
	std::cout << std::endl;
}
