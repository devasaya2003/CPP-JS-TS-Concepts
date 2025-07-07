#include <iostream>
#include <cstdint> // for uintptr_t

/*
uintptr_t is an **unsigned integer type** that is capable of storing a pointer.

Why do we use it here?
When you subtract two pointers (like &arr[1] - &arr[0]), you get a value 
in terms of how many elements apart they are — *not* the raw byte difference.

But we want to know the actual number of **bytes** between two memory addresses.

To do that, we:
1. Cast both pointer addresses to uintptr_t — this gives us the raw memory address as an integer.
2. Subtract the two integers to get the byte-level distance between them.

This helps us confirm that the array elements are stored contiguously,
and that the gap between them matches the size of one `int`.
*/

using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "Array base address: " << arr << endl;
    cout << "Pointer address:    " << ptr << endl;

    cout << "\nAccessing elements:\n";

    for (int i = 0; i < 5; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i]
             << " | *(ptr + " << i << ") = " << *(ptr + i)
             << " | Memory Address casted to Integer = " << (uintptr_t)(ptr + i) << endl;
    }

    cout << "\nSizes:\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";

    uintptr_t diff = (uintptr_t)&arr[1] - (uintptr_t)&arr[0];
    cout << "Address difference between arr[0] and arr[1]: "
         << diff << " bytes\n";

    return 0;
}
