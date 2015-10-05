#include <map>
#include <string>

typedef std::map<std::string, std::string> DataObjectTree; 


class DataObject : public std::string
{
	public:
		DataObject(std::string str) : std::string(str){};
		DataObject(const char *str) : std::string(str){};
		const DataObject& operator[](DataObject);
		DataObject operator=(DataObject);
		DataObjectTree::iterator begin();
		DataObjectTree::iterator end();
	private:
		DataObjectTree tree;
		DataObject fetch(DataObject& object);

};

typedef std::map<std::string, DataObject(*)(DataObject&)> DispatchTable;

class ObjectProvider : DataObject
{
	public:
		DataObject request(DataObject& object);
	private:
		DispatchTable dispatch;
};
