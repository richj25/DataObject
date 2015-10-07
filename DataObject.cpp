#include "DataObject.h"
#include <iostream>

DataObject& DataObject::operator[](DataObject object)
{
	return tree[object];
}

DataObjectTree::iterator DataObject::begin()
{
	return tree.begin();
}

DataObjectTree::iterator DataObject::end()
{
	return tree.end();
}

DataObject DataObject::operator=(const char* str)
{
	std::string::operator=(str);
	return *this;
}

DataObject DataObject::operator=(std::string str)
{
	std::string::operator=(str);
	return *this;
}

DataObject DataObject::operator=(DataObject object)
{
	std::string::operator=(object);

	DataObjectTree::iterator iter = object.begin();
	for (; iter != object.end(); iter++)
	{
		this->tree[iter->first] = iter->second;
	}

	return *this;
}

void DataObject::dump()
{
	static std::string indent;
	indent += "	";

	DataObjectIterator iter = begin();
	for (; iter != end(); iter++)
	{
		std::cout << indent << iter->first << "->" << iter->second << std::endl;
		iter->second.dump();	
	}

	indent.erase(0,1);
}

DataObject& ProviderObject::operator[](DataObject object)
{
	if (this->tree.count(object) == 0)
	{
		this->tree[object] = fetch(object);
	}

	return tree[object];
}

DataObject ProviderObject::fetch(DataObject object)
{
	return "fetching " + object;
}
