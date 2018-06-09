#include "List.h"
#include <utility>

int main()
{
	std::cout << std::boolalpha;

	List<int> list;

	std::cout << "Is the list empty? : " << list.empty() << "\n\n";
	std::cout << "Created list :\n";
	list.addEnd(5);
	list.addFront(0);
	list.addFront(0);
	list.addFront(3);
	list.addFront(0);
	list.addEnd(3);
	list.addEnd(0);
	list.addEnd(3);

	list.print();
	std::cout << "Size : " << list.size() << '\n';
	std::cout << "Is the list empty? : " << list.empty() << '\n';
	
	std::cout << "\nAfter removing first node :\n";
	list.removeFront();
	list.print();
	std::cout << "Size : " << list.size() << '\n';

	std::cout << "\nAfter removing last node :\n";
	list.removeEnd();
	list.print();
	std::cout << "Size : " << list.size() << '\n';

	std::cout << "\nCopied list :\n";
	List<int> copy(list);
	copy.print();
	std::cout << "Size : " << copy.size() << '\n';

	std::cout << "\nMoved list :\n";
	List<int> moved(std::move(list));
	moved.print();
	std::cout << "Size : " << moved.size() << "\n\n";

	std::cout << "List after moving :\n";
	list.print();
	std::cout << "Size : " << list.size() << '\n';

	return 0;
}