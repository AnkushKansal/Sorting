/*Quick Sort Algo.
	Divide and conquer method. First partition and find pivot , then take on each half of pivot.
	Time complexity :
		T(n) = n(to pivot) + 2T(n/2) n>1 
				 0 n = 1 
		O(nlogn)/O(n^2)if sorted or reverse(worst situation)

	Space Complexity 
		S(n)= O(logn) / O(n) Only stack size as we not acquire extra space like we do in merge sort.
*/
#include<iostream>

int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);

int main()
{
	int arr[] = { 23, 43, 56, 32, 1, 8, 0, 67, 54, 1002, 30, 47 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size - 1); //See I am passing right-1 index(rightmost element to compare). Algo on index. Can twitch and can pass size too.

	for (int i = 0; i < size; i++)
	{
		std::cout << "  " << arr[i];
	}
}

int partition(int* arr, int left, int right)
{
	int temp = 0;
	int j = left;
	int i = left - 1;
	int value = arr[right];

	//traverse each element till last-1 comparing the value
	while (j < right)
	{
		if (arr[j] <= value)
		{
			i++;
			//swap arr[j] and arr[i]. Means just preserve small ones on left.			
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}

	temp = arr[i+1];
	arr[i + 1] = value;
	arr[right] = temp;

	return i + 1; //pivot elememt index
}

void quickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int index = partition(arr, left, right);
		quickSort(arr, left, index-1);
		quickSort(arr, index + 1, right);
	}
}
