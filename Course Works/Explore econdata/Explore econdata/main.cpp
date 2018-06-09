#include "Menu.h"
#include "State.h"

int main()
{
	std::ifstream inf("econ_data.txt");

	if (!inf)
	{
		std::cerr << "File couldn't be opened for reading!" << std::endl;
		return 0;
	}

	int numStates;
	inf >> numStates;
	State *states = allocateStates(numStates);

	readStateData(states, numStates, inf);

	   
	// ================================================

	menu(states, numStates);

	freeStateData(states);
	return 0;
}