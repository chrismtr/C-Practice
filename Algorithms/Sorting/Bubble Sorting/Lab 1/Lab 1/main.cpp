#include <ctime>
#include <iostream>
#include <utility>

void createArray(double *array, int length);
double getRandom(double min, double max);
void printArray(const double *array, int length);
void sortAscending(double *array, int length);
void sortDescending(double *array, int length);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const int length = getRandom(0, 20);
	double *array = new double[length];

	std::cout << "Created array :\n";
	createArray(array, length);
	printArray(array, length);

	std::cout << "Sorted in ascending order :\n";
	sortAscending(array, length);
	printArray(array, length);

	std::cout << "Recreated array :\n";
	createArray(array, length);
	printArray(array, length);

	std::cout << "Sorted in descending order :\n";
	sortDescending(array, length);
	printArray(array, length);

	delete[] array;
	return 0;
}

void createArray(double *array, int length)
{
	const double min = 0;
	const double max = 100;

	for (int count = 0; count < length; ++count)
		array[count] = getRandom(min, max);
}

double getRandom(double min, double max)
{
	double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return fraction * rand() * (max - min + 1) + min;
}

void printArray(const double *array, int length)
{
	for (int count = 0; count < length; ++count)
		std::cout << array[count] << ' ';
	std::cout << '\n';
}

void sortAscending(double *array, int length)
{
	bool isSorted;
	do
	{
		isSorted = true;
		for (int count = 0; count < length - 1; ++count)
			if (array[count] > array[count + 1])
			{
				std::swap(array[count], array[count + 1]);
				isSorted = false;
			}
	} while (!isSorted);
}

void sortDescending(double *array, int length)
{
	bool isSorted;
	do
	{
		isSorted = true;
		for (int count = 0; count < length - 1; ++count)
			if (array[count + 1] > array[count])
			{
				std::swap(array[count], array[count + 1]);
				isSorted = false;
			}
	} while (!isSorted);
}