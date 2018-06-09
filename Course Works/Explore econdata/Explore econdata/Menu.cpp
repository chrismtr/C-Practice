#include "Menu.h"

void menu(State *states, int numStates)
{
	int item;
	while (true)
	{
		std::cout << "==============================  Menu  ==============================\n";
		std::cout << "0 - [Print the state with the highest median household income.]\n";
		std::cout << "1 - [Print the state with the lowest median household income.]\n";
		std::cout << "2 - [Print the state with the highest unemployment in 2015.]\n";
		std::cout << "3 - [Print the state with the lowest unemployment in 2015.]\n";
		std::cout << "4 - [Print the states in sorted order by change in unemployment from 2007 to 2015.]\n";
		std::cout << "5 - [Print the states in sorted order based on median household income.]\n";
		std::cout << "6 - [Select a state and then:]\n";
		std::cout << "7 - [Exit]\n\n";

		std::cin >> item;
		std::cout << "======================================================================\n\n";

		switch (item)
		{
		case 0:
			printHighestMedIncome(states, numStates);
			break;
		case 1:
			printLowestMedIncome(states, numStates);
			break;
		case 2:
			printHighestUnempl_2015(states, numStates);
			break;
		case 3:
			printLowestUnempl_2015(states, numStates);
			break;
		case 4:
			printByUnempl(states, numStates);
			break;
		case 5:
			printByMedIncome(states, numStates);
			break;
		case 6:
		{
			std::cout << "Choose state (from 0 to " << numStates - 1 << ")\n";
			int stateIndex;
			std::cin >> stateIndex;
			if (stateIndex < 0 || stateIndex > numStates - 1)
			{
				std::cout << "Error!\n";
				break;
			}
			menuCounties(states[stateIndex].counties, states[stateIndex].numCounties);
			break;
		}
		case 7:
			return;
		default:
			std::cout << "Error!\n";
		}
		std::cout << "\n\n";
	}
}

void menuCounties(County *counties, int numCounties)
{
	int countyItem;
	
	while (true)
	{
		std::cout << "\t==============================  Menu  ==============================\n";
		std::cout << "\t0 - [Print the county with the highest median household income.]\n";
		std::cout << "\t1 - [Print the county with the lowest median household income.]\n";
		std::cout << "\t2 - [Print the county with the highest unemployment in 2015.]\n";
		std::cout << "\t3 - [Print the county with the lowest unemployment in 2015.]\n";
		std::cout << "\t4 - [Print the county in sorted order by change in unemployment from 2007 to 2015.]\n";
		std::cout << "\t5 - [Print the county in sorted order based on median household income.]\n";
		std::cout << "\t6 - [Exit]\n\n";
		std::cin >> countyItem;
		std::cout << "======================================================================\n\n";

		switch (countyItem)
		{
		case 0:
			printHighestMedIncome(counties, numCounties);
			break;
		case 1:
			printLowestMedIncome(counties, numCounties);
			break;
		case 2:
			printHighestUnempl_2015(counties, numCounties);
			break;
		case 3:
			printLowestUnempl_2015(counties, numCounties);
			break;
		case 4:
			printByUnempl(counties, numCounties);
			break;
		case 5:
			printByMedIncome(counties, numCounties);
			break;
		case 6:
			return;
		default:
			std::cout << "Error!\n";
		}
		std::cout << "\n\n";
	}
}