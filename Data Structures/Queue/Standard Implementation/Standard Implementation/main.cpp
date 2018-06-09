#include "Queue.h"

int main()
{
	Queue<int> queue;
	std::cout << std::boolalpha;
	std::cout << "Is the queue empty? : " << queue.empty() << '\n';

	for (int count = 1; count <= 20; ++count)
		queue.push(count);
	std::cout << "Created queue :\n";
	queue.print();
	std::cout << "Size : " << queue.size() << '\n';
	std::cout << "Is the queue empty? : " << queue.empty() << '\n';

	std::cout << "=========================================\n";
	std::cout << "Queue after popping :\n";
	queue.pop();
	queue.print();
	std::cout << "Size : " << queue.size() << '\n';

	std::cout << "=========================================\n";
	std::cout << "Front node : " << (queue.front())->getData() << '\t' << queue.front() << '\n';
	std::cout << "Back node : " << (queue.back())->getData() << '\t' << queue.back() << '\n';
	std::cout << "=========================================\n";
	std::cout << "Copy :\n";
	Queue<int> copy(queue);
	copy.print();
	std::cout << "Size : " << copy.size() << '\n';
	std::cout << "Is the queue empty? : " << copy.empty() << '\n';

	return 0;
}