#include<iostream>

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr1[], int left, int right);


int main()
{
	int arr[] = { 23, 43, 56, 32, 1, 8, 0, 67, 54, 1002, 30, 47 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, size - 1); //See I am passing right-1 index. algo on index. Can twitch and can pass size too

	for (int i = 0; i < size; i++)
	{
		std::cout << "  " << arr[i];
	}
	
}

void mergeSort(int *arr1, int left, int right)
{
	if (left == right) return;

	int mid = (left + right) / 2;
	mergeSort(arr1, left, mid);
	mergeSort(arr1, mid+1, right);
	merge(arr1, left, mid, right);
}

void merge(int *arr, int left, int mid, int right)
{
	const int size1 = mid - left + 1;
	const int size2 = right - mid;

	int* temparr1 = new int[size1];
	int* temparr2 = new int[size2];

	for (int i = 0; i < size1; i++)
		temparr1[i] = arr[left+i];

	for (int i = 0; i < size2; i++)
		temparr2[i] = arr[mid+1+i];

	int i, j, k;
	i = j = 0;
	k = left;

	while (i < size1 && j < size2)
	{
		//Algo is stable sort. Order maintained
		if (temparr1[i] <= temparr2[j])
		{
			arr[k] = temparr1[i];
			k++; i++;
		}

		else
		{
			arr[k] = temparr2[j];
			k++; j++;
		}
	}

	//In case if any of the one array is done copying , just copy the another array.
	while (i < size1)
	{
		arr[k] = temparr1[i];
		i++, k++;
	}

	while (j < size2)
	{
		arr[k] = temparr2[j];
		j++, k++;
	}
}