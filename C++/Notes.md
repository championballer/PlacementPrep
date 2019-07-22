## C++

### Important Links
1. https://www.geeksforgeeks.org/c-magicians-stl-algorithms/
2. https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
3. https://www.geeksforgeeks.org/storage-classes-in-c/
4. https://www.geeksforgeeks.org/namespace-in-c/

### Important points to remember
1. enum is a user defined data type which takes only the values defined by the user. For example, 

```cpp
enum direction{North,South,East,West};

direction dir;
dir = South;
cout<<dir<<endl;//3
```

Used to have a stricter check over the possible values that a variable can undertake.

2. Defining your own namespace. What exactly is namespace.
3. Only one main function per namespace. There can be two if different namespace are defined. Using namespaces variables or functions of the same can be used in the same function. The rule primarily is that there can be only one variable of a certain name in one namespace. Namespace specific variables can be used using scope(::) operator.

Arguments to main through command line.
4. Faster i/o
5. Assignment operator is the only operator which can be overloaded but cannot be inherited.
6. Bitwise operators work with only integral data types like char\, int and long and not with floating point values.
7. Working of left shift and right shift bitwise operators.
8. Comma operator and sequence points. 
9. sizeof works without paranthesis as well.
10. Typedef used to assign different call signs to existing types.
11. In Pointers * binds to the right and not the left. i.e. only one pointer is declared in a line. To declare multiple pointers in a line, typedef can be used.

```cpp
int *x, y;
```

Only x is a pointer whereas y isn't.

```cpp
typedef int* IntPtr ;
IntPtr x, y, z;
```

12. Storage classes in cpp.
	1. Global
	2. Local(auto)
	3. Static
	4. Register
	5. Extern : 
13. Important functions in algorithm library. 
14. Use of bitset in C++ for handling bit manipulation and bit centric questions.
15. Difference between parameters(Mentioned in declaration/definition) and arguments(Actually sent). Declaration of a function needs a semicolon whereas definition doesn't. Declaration doesn't lead to allocation of memory whereas definition does. Therefore multiple declaration is okay, but definition is not. 
16. Basic idea of operator precedence.
17. Header file inclusion multiple times.
