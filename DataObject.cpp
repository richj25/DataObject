#include "DataObject.h"

const DataObject& DataObject::operator[](DataObject object)
{
	if (this->tree.count(object) == 0)
	{
		this->tree.insert(std::pair<DataObject, DataObject>(object, fetch(object)));
	}
	DataObjectIterator iter = this->begin()
	for (; iter != this->end(); iter++)
	return (DataObject)this->tree[object];
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
	object = *this;

	DataObjectTree::iterator iter = this->begin();
	for (; iter != this->end(); iter++)
	{
		object.tree.insert(*iter);
	}
	return *this;
}

DataObject DataObject::fetch(DataObject& object)
{
	return "Not Supported";
}
