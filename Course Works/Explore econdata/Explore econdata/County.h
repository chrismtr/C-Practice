#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

struct County
{
	std::string name;
	double unemployed_2007;
	double unemployed_2015;
	int medIncome;
};

County  *allocateCounties(int numCounties);
void readCountyData(County *counties, int numCounties, std::ifstream &inf);

void printCounty(County *counties, int countyIndex);
void printHighestMedIncome(County *counties, int numCounties);
void printLowestMedIncome(County *counties, int numCounties);
void printHighestUnempl_2015(County *counties, int numCounties);
void printLowestUnempl_2015(County *counties, int numCounties);
void printByUnempl(County *counties, int numCounties);
void printByMedIncome(County *counties, int numCounties);