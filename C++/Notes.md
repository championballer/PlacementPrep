## C++

1. enum is a user defined data type which takes only the values defined by the user. For example, 

```cpp
enum direction{North,South,East,West};

direction dir;
dir = South;
cout<<dir<<endl;//3
```

Used to have a stricter check over the possible values that a variable can undertake.

2. Defining your own namespace. What exactly is namespace.
3. Only one main function per namespace. There can be two if different namespace are defined. 
4. Faster i/o
5. Assignment operator is the only operator which can be overloaded but cannot be inherited.
6. Bitwise operators work with only integral data types like char\, int and long and not with floating point values.
7. Working of left shift and right shift bitwise operators.
8. Comma operator and sequence points. 
9. sizeof works without paranthesis as well.
10. Typedef used to assign different call signs to existing types.
11. In Pointers * binds to the right and not the left. i.e. only one pointer is declared in a line. To declare multiple pointers in a line, typedef can be used.

```cpp
typedef int* IntPtr ;
IntPtr x, y, z;
```
