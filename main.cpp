#include <iostream>
#include "DataObject.h"

int main()
{
	DataObject object("rich");

	object[DataObject("Guid")] = "1234";
	// object["Guid"]["Manageability"] = "True";

	// std::cout << object << std::endl;
}
