#include "County.h"

County *allocateCounties(int numCounties)
{
	County *counties = new County[numCounties];

	return counties;
}

void readCountyData(County *counties, int numCounties, std::ifstream &inf)
{
	for (int count = 0; count < numCounties; ++count)
		inf >> counties[count].name >> counties[count].unemployed_2007 >> counties[count].unemployed_2015 >> counties[count].medIncome;
}

void printCounty(County *counties, int countyIndex)
{
	std::cout << "County name : " << counties[countyIndex].name << '\n';
	std::cout << "2007 unemployment rate : " << counties[countyIndex].unemployed_2007 << '\n';
	std::cout << "2015 unemployment rate : " << counties[countyIndex].unemployed_2015 << '\n';
	std::cout << "Median household income : " << counties[countyIndex].medIncome << "\n\n";
}

void printHighestMedIncome(County *counties, int numCounties)
{
	int maxIndex = 0;

	for (int count = 1; count < numCounties; ++count)
		if (counties[count].medIncome > counties[maxIndex].medIncome)
			maxIndex = count;
	std::cout << "The county with the highest median household income :\n";
	printCounty(counties, maxIndex);
}

void printLowestMedIncome(County *counties, int numCounties)
{
	int minIndex = 0;

	for (int count = 1; count < numCounties; ++count)
		if (counties[count].medIncome < counties[minIndex].medIncome)
			minIndex = count;
	std::cout << "The county with the lowest median household income :\n";
	printCounty(counties, minIndex);
}

void printHighestUnempl_2015(County *counties, int numCounties)
{
	int maxIndex = 0;

	for (int count = 1; count < numCounties; ++count)
		if (counties[count].unemployed_2015 > counties[maxIndex].unemployed_2015)
			maxIndex = count;
	std::cout << "The county with the highest unemployment in 2015 :\n";
	printCounty(counties, maxIndex);
}

void printLowestUnempl_2015(County *counties, int numCounties)
{
	int minIndex = 0;

	for (int count = 1; count < numCounties; ++count)
		if (counties[count].unemployed_2015 < counties[minIndex].unemployed_2015)
			minIndex = count;
	std::cout << "The county with the lowest unemployment in 2015 :\n";
	printCounty(counties, minIndex);
}


void printByUnempl(County *counties, int numCounties)
{
	bool isSorted;

	do
	{
		isSorted = true;
		for (int count = 0; count < numCounties - 1; ++count)
		{
			if ((counties[count].unemployed_2015 - counties[count].unemployed_2007) >(counties[count + 1].unemployed_2015 - counties[count + 1].unemployed_2007))
			{
				std::swap(counties[count], counties[count + 1]);
				isSorted = false;
			}
		}

	} while (!isSorted);

	for (int count = 0; count < numCounties; ++count)
		printCounty(counties, count);
}

void printByMedIncome(County *counties, int numCounties)
{
	bool isSorted;

	do
	{
		isSorted = true;
		for (int count = 0; count < numCounties - 1; ++count)
		{
			if (counties[count].medIncome < counties[count + 1].medIncome)
			{
				std::swap(counties[count], counties[count + 1]);
				isSorted = false;
			}
		}

	} while (!isSorted);

	for (int count = 0; count < numCounties; ++count)
		printCounty(counties, count);
}