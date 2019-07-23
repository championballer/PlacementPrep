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

2. Binary Searching. Can be applied on a sorted array. Prototype ```binary_search(startaddress, endaddress, valuetofind)``. This returns whether the element is present in the sorted array or not.
3. Inserting multiple values in a vector at a given postion.

```cpp
vector<int> arr;
arr.insert(arr.end(),{1,2,3,4,5});
```


