## Questions

1. Rearrange an array such that arr[i] = i
Given an array of elements of length N, ranging from 0 to N – 1. All elements may not be present in the array. If element is not present then there will be -1 present in the array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.
	Method : Iterate over the array, and for each index check whether it is at
	correct position or not. If not then exchange and then check for that element 
	-> O(n)

2. 