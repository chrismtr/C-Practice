#include <cstdlib>
#include <ctime>
#include <iostream>

void fillArray(int *array, int length);
int getRandom(int min, int max);
int linearSearch(int *array, int length, int key);
void printArray(int *array, int length);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int *array = new int[10]{};

	fillArray(array, 10);
	printArray(array, 10);
	
	int index = linearSearch(array, 10, 10);
	if (index > -1)
	{
		std::cout << "Element # " << index + 1 << "contains 10";
	}
	else {
		std::cout << "Element wasn't found\n";
	}

	delete[] array;
	return 0;
}

void fillArray(int *array, int length)
{
	for (int count = 0; count < length; ++count)
		array[count] = getRandom(0, 100);
}

int getRandom(int min, int max)
{
	double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int linearSearch(int *array, int length, int key)
{
	for (int count = 0; count < length; ++count)
		if (array[count] == key)
			return count;
	return -1;
}

void printArray(int *array, int length)
{
	for (int count = 0; count < length; ++count)
		std::cout << array[count] << '\t';
	std::cout << '\n';
}