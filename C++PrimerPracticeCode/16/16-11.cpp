typedef int elemType;

template <typename elemType> class ListItem;
template <typename elemType> class List
{
public:
	List() = default;
private:
	ListItem<elemType> *front, *end;
};


int main()
{
	List<int> l;

	return 0;
}