#include<iostream>
#include<chrono>

typedef std::chrono::high_resolution_clock Myclock;

template<typename T = void>
void InsertionSort(T arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int value = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > value)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = value;
	}
}

int main()
{
	int arr1[] = { 2, 4, 1, 9, 7, 0, 6, 11, 19, 18, 120, 33, 45, 56, 23, 31 };
	int size = sizeof(arr1) / sizeof(arr1[0]);

	auto startTime = Myclock::now();
	InsertionSort(arr1, size);
	auto stopTime = Myclock::now();

	std::cout << "time taken is " << std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime).count() << std::endl;

	std::cout << "Sorted array is " << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << arr1[i] << " ";
	}

	std::cin.get();
}