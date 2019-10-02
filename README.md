# Sorting
 Contains various sorting algorithms

Merge Sort Algorithm: 

Space Complexity : n + log(n)  Tree height = O(n)
Time Complexity :  n + 2T(n/2) = O(nlogn)


--------------------------------

Insertion Sort Algorithm:

Space Complexity : O(1) as it does in place sorting
Time Complexity : O(n^2) . Compare each card with each on left.

--------------------------------

QuickSort Algorithm:

Space Complexity : O(logn) as it does in place sorting
Time Complexity :  O(nlogn) as fiding pivot iterates over each and then each half	
				   O(n^2) if list is already sorted or reverse.
				   
	T(n) =	n + 2T(n/2) if n > 1
			1			if n = 1
			
	If list is already sorted 
	T(n) =	n + T(n-1)	if left < right
			1			if left == right
		
--------------------------------
