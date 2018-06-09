#pragma once

#include "County.h"

struct State
{
	std::string name;
	double unemployed_2007;
	double unemployed_2015;
	int medIncome;
	County *counties;
	int numCounties;
};

State *allocateStates(int numStates);
void readStateData(State *states, int numStates, std::ifstream &inf);
void freeStateData(State *states);

void printState(State *states, int stateIndex);
void printHighestMedIncome(State *states, int numStates);
void printLowestMedIncome(State *states, int numStates);
void printHighestUnempl_2015(State *states, int numStates);
void printLowestUnempl_2015(State *states, int numStates);
void printByUnempl(State *states, int numStates);
void printByMedIncome(State *states, int numStates);