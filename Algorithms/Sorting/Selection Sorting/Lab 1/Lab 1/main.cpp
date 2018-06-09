#include <ctime>
#include <iostream>
#include <utility>

void createArray(int *array, int length);
int getRandom(int min, int max);
void printArray(const int *array, int length);
void sortAscending(int *array, int length);
void sortDescending(int *array, int length);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const int length = getRandom(2, 20);
	int *array = new int[length];

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

void createArray(int *array, int length)
{
	const int min = 0;
	const int max = 50;

	for (int count = 0; count < length; ++count)
		array[count] = getRandom(min, max);
}

int getRandom(int min, int max)
{
	double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(fraction * rand() * (max - min + 1) + min);
}

void printArray(const int *array, int length)
{
	for (int count = 0; count < length; ++count)
		std::cout << array[count] << ' ';
	std::cout << '\n';
}

void sortAscending(int *array, int length)
{
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		int maxIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
			if (array[maxIndex] > array[currentIndex])
				maxIndex = currentIndex;
		std::swap(array[startIndex], array[maxIndex]);
	}
}

void sortDescending(int *array, int length)
{
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		int maxIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
			if (array[currentIndex] > array[maxIndex])
				maxIndex = currentIndex;
		std::swap(array[startIndex], array[maxIndex]);
	}
}