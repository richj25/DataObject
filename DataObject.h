#include <map>
#include <string>

class DataObject;

typedef std::map<DataObject, DataObject> DataObjectTree; 

class DataObject : public std::string
{
	public:
		DataObject() : std::string(""){};
		DataObject(std::string str) : std::string(str){};
		DataObject(const char *str) : std::string(str){};
		DataObject& operator[](DataObject);
		DataObject operator=(DataObject);
		DataObjectTree::iterator begin();
		DataObjectTree::iterator end();
		DataObjectTree tree;
};

typedef std::map<std::string, DataObject(*)(DataObject&)> DispatchTable;

class ProviderObject : private DataObject
{
	public:
		DataObject request(DataObject& object);
		DataObject operator[](DataObject);
	private:
		DispatchTable dispatch;
		DataObject fetch(DataObject);
};
