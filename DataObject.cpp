#include "DataObject.h"
#include <iostream>
DataObject& DataObject::operator[](DataObject object)
{
	return tree[object];
}

DataObject ProviderObject::operator[](DataObject object)
{
	DataObject returnObject;
	if (this->tree.count(object) == 0)
	{
		returnObject = std::string(fetch(object));
		if (std::string(returnObject) != "Error")
		{	
			this->tree.insert(std::pair<DataObject, DataObject>(object, returnObject));
		}
	}

	DataObjectTree::iterator iter = begin();
	for (; iter != end(); iter++)
	{
		if (iter->first == object)
		{
			returnObject = iter->second;
			break;
		}
	}

	return returnObject;
}

DataObjectTree::iterator DataObject::begin()
{
	return tree.begin();
}

DataObjectTree::iterator DataObject::end()
{
	return tree.end();
}

DataObject DataObject::operator=(DataObject object)
{
	std::string::operator=(std::string(object));

	DataObjectTree::iterator iter = object.begin();
	for (; iter != object.end(); iter++)
	{
		this->tree.insert(*iter);
	}
	return *this;
}

DataObject ProviderObject::fetch(DataObject object)
{
	return "Not Supported";
}
