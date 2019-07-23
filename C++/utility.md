1. Sorting - Quicksort is used in STL's sort(). Consequently the time complexity for the same is O(N*logN) sort(start\_address, end\_address).

```cpp

vector<int> a;
sort(a.begin(),a.end());

```

To sort in descending order, we use sort(a.begin(),a.end(),greater<int>());

We can also write our own comparator function which can be passed to sort in a way that is suitable to our needs. This can be used to sort user defined objects and variables as well. 

```cpp
bool compare(interval i1, interval i2)
{
	return i1.begin<i2.begin;
}

```

There is another way of doing the same, is by overloading the '<' operator for the class or the user defined variable. This is something which can be used in all data structures which use ordering, such as set, priority queue, map.

```cpp
bool operator < (const node & g)const{
	return b<g.b;
}
```

The following function can be written if the overloading needs to be done outside class. (Used in merging K sorted lists)
```cpp
struct CompareHeight { 
    bool operator()(Person const& p1, Person const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.height < p2.height; 
    } 
}; 

```

2. Binary Searching. Can be applied on a sorted array. Prototype ```binary_search(startaddress, endaddress, valuetofind)``. This returns whether the element is present in the sorted array or not.
3. Inserting multiple values in a vector at a given postion.

```cpp
vector<int> arr;
arr.insert(arr.end(),{1,2,3,4,5});
```
4. isalpha() and isdigit() can be used while processing strings to easily check for alphabets and digits.
5. reverse(arr.begin(),arr.end()) - to reverse vector or string
6. max_element(arr.begin(),arr.end()) - to find max in a range of a given array. Returns iterator to element. So dereference to access. 
7. min_element(arr.begin(),arr.end()) 
8. accumulate(first\_iterator, last\_iterator, initial value of sum) – Does the summation of vector elements. It is important to mention the initial sum. Doesn't take 0 by default;
9. count(arr.begin(),arr.end(),element) - Counts the occurrences of element in given range of addresses;
10. find(arr.begin(),arr.end(),element)
11. lower\_bound(first\_iterator, last\_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.
12. upper\_bound(first\_iterator, last\_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’.


