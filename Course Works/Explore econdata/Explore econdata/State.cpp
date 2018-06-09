#include "State.h"

State *allocateStates(int numStates)
{
	State *states = new State[numStates];

	return states;
}

void readStateData(State *states, int numStates, std::ifstream &inf)
{
	for (int count = 0; count < numStates; ++count) {
		inf >> states[count].name >> states[count].unemployed_2007 >> states[count].unemployed_2015 >> states[count].medIncome >> states[count].numCounties;
		states[count].counties = allocateCounties(states[count].numCounties);
		readCountyData(states[count].counties, states[count].numCounties, inf);
	}
}

void freeStateData(State *states)
{
	delete[] states;
}

void printState(State *states, int stateIndex)
{
	std::cout << "State name : " << states[stateIndex].name << '\n';
	std::cout << "2007 unemployment rate : " << states[stateIndex].unemployed_2007 << '\n';
	std::cout << "2015 unemployment rate : " << states[stateIndex].unemployed_2015 << '\n';
	std::cout << "Median household income : " << states[stateIndex].medIncome << "\n\n";
}

void printHighestMedIncome(State *states, int numStates)
{
	int maxIndex = 0;
	for (int count = 1; count < numStates; ++count)
		if (states[count].medIncome > states[maxIndex].medIncome)
			maxIndex = count;
	
	std::cout << "The state with the highest median household income :\n";
	printState(states, maxIndex);
}

void printLowestMedIncome(State *states, int numStates)
{
	int minIndex = 0;
	for (int count = 1; count < numStates; ++count)
		if (states[count].medIncome < states[minIndex].medIncome)
			minIndex = count;

	std::cout << "The state with the lowest median household income :\n";
	printState(states, minIndex);
}

void printHighestUnempl_2015(State *states, int numStates)
{
	int maxIndex = 0;
	for (int count = 1; count < numStates; ++count)
		if (states[count].unemployed_2015 > states[maxIndex].unemployed_2015)
			maxIndex = count;

	std::cout << "The state with the highest unemployment in 2015 :\n";
	printState(states, maxIndex);
}

void printLowestUnempl_2015(State *states, int numStates)
{
	int minIndex = 0;
	for (int count = 1; count < numStates; ++count)
		if (states[count].unemployed_2015 < states[minIndex].unemployed_2015)
			minIndex = count;

	std::cout << "The state with the lowest unemployment in 2015 :\n";
	printState(states, minIndex);
}

void printByUnempl(State *states, int numStates)
{
	bool isSorted;

	do
	{
		isSorted = true;
		for (int count = 0; count < numStates - 1; ++count)
		{
			if ((states[count].unemployed_2015 - states[count].unemployed_2007) > (states[count + 1].unemployed_2015 - states[count + 1].unemployed_2007))
			{
				std::swap(states[count], states[count + 1]);
				isSorted = false;
			}
		}

	} while (!isSorted);

	for (int count = 0; count < numStates; ++count)
		printState(states, count);
}

void printByMedIncome(State *states, int numStates)
{
	bool isSorted;

	do
	{
		isSorted = true;
		for (int count = 0; count < numStates - 1; ++count)
		{
			if (states[count].medIncome < states[count + 1].medIncome)
			{
				std::swap(states[count], states[count + 1]);
				isSorted = false;
			}
		}

	} while (!isSorted);

	for (int count = 0; count < numStates; ++count)
		printState(states, count);
}