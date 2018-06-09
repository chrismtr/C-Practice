#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

void fillArray(int *array, int length);
int getRandom(int min, int max);
void printArray(int *array, int length);
void quickSortAscending(int *array, int left, int right);
void quickSortDescending(int *array, int left, int right);
int partitionAscending(int *array, int left, int right, int pivot);
int partitionDescending(int *array, int left, int right, int pivot);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const int length = getRandom(2, 100);
	int *array = new int[length];

	fillArray(array, length);
	printArray(array, length);
	quickSortAscending(array, 0, length - 1);
	printArray(array, length);
	quickSortDescending(array, 0, length - 1);
	printArray(array, length);

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

void printArray(int *array, int length)
{
	for (int count = 0; count < length; ++count)
		std::cout << array[count] << '\t';
	std::cout << "\n\n";
}

void quickSortAscending(int *array, int left, int right)
{
	if (left >= right)
		return;

	int pivot = array[left + (right - left) / 2];
	int index = partitionAscending(array, left, right, pivot);

	quickSortAscending(array, left, index - 1);
	quickSortAscending(array, index, right);
}

void quickSortDescending(int *array, int left, int right)
{
	if (left >= right)
		return;

	int pivot = array[left + (right - left) / 2];
	int index = partitionDescending(array, left, right, pivot);

	quickSortDescending(array, left, index - 1);
	quickSortDescending(array, index, right);
}

int partitionAscending(int *array, int left, int right, int pivot)
{
	while (right >= left)
	{
		while (array[left] < pivot)
			++left;
		while (array[right] > pivot)
			--right;

		if (left <= right)
		{
			std::swap(array[left], array[right]);
			++left;
			--right;
		}
	}
	return left;
}

int partitionDescending(int *array, int left, int right, int pivot)
{
	while (right >= left)
	{
		while (array[left] > pivot)
			++left;
		while (array[right] < pivot)
			--right;

		if (left <= right)
		{
			std::swap(array[left], array[right]);
			++left;
			--right;
		}
	}
	return left;
}