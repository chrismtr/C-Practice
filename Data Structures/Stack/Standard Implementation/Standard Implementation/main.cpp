#include "Stack.h"

int main()
{
	Stack<int> stack;
	std::cout << std::boolalpha << "Is the stack empty ? : " << stack.empty() << '\n';
	for(int count = 20; count >= 0; --count)
		stack.push(count);
	std::cout << "==================================================================================\n";
	std::cout << "Created stack :\n";
	stack.print();

	std::cout << "[ Size : " << stack.size() << " ]\n";
	std::cout << std::boolalpha << "Is the stack empty ? : " << stack.empty() << '\n';
	std::cout << "==================================================================================\n";
	stack.pop();
	std::cout << "Stack after popping :\n";
	stack.print();
	std::cout << "[ Size : " << stack.size() << " ]\n";

	std::cout << "Copy :\n";
	Stack<int> copy(stack);
	copy.print();
	std::cout << "[ Size : " << copy.size() << " ]\n";

	return 0;
}