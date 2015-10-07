#include <map>
#include <string>

class DataObject;

typedef std::map<DataObject, DataObject> DataObjectTree; 
typedef DataObjectTree::iterator DataObjectIterator;
class DataObject : public std::string
{
	public:
		DataObject() : std::string(""){};
		DataObject(std::string str) : std::string(str){};
		DataObject(const char *str) : std::string(str){};
		DataObject& operator[](DataObject);
		DataObject operator=(DataObject);
		DataObject operator=(const char *);
		DataObject operator=(std::string);
		DataObjectIterator begin();
		DataObjectIterator end();
		void dump();
		DataObjectTree tree;
};


class ProviderObject : public DataObject
{
	public:
		DataObject& operator[](DataObject);
	private:
		DataObject fetch(DataObject);
		DataObject firstObject;
		DataObject lastObject;
};
