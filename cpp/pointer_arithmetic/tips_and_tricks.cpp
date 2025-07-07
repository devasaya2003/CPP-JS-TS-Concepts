#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

void trick1() {
    cout << "\n🔹 Trick 1: Accessing array elements with pointer arithmetic\n";
    int arr[3] = {10, 20, 30};
    cout << "Initial array: [" << arr[0] << ", " << arr[1] << ", " << arr[2] << "]\n";
    int* ptr = arr;
    cout << "ptr points to first element: " << *ptr << "\n";
    cout << "Using pointer arithmetic to access second element:\n";
    cout << "*(ptr + 1) = " << *(ptr + 1) << " (accessing index 1)\n";
    cout << "This is equivalent to arr[1] = " << arr[1] << "\n";
}

void trick2() {
    cout << "\n🔹 Trick 2: Swapping values without a temp variable (using pointers)\n";
    int a = 5, b = 10;
    cout << "Initial values: a = " << a << ", b = " << b << "\n";
    int* pa = &a;
    int* pb = &b;
    cout << "Creating pointers to a and b\n";
    cout << "Performing swap using arithmetic operations:\n";
    *pa = *pa + *pb;  // a = 5 + 10 = 15
    cout << "Step 1: *pa = *pa + *pb → a = " << *pa << "\n";
    *pb = *pa - *pb;  // b = 15 - 10 = 5
    cout << "Step 2: *pb = *pa - *pb → b = " << *pb << "\n";
    *pa = *pa - *pb;  // a = 15 - 5 = 10
    cout << "Step 3: *pa = *pa - *pb → a = " << *pa << "\n";
    cout << "Final values: a = " << *pa << ", b = " << *pb << " (swapped!)\n";
}

void trick3() {
    cout << "\n🔹 Trick 3: Pointer to array vs pointer to first element\n";
    int arr[2] = {1, 2};
    cout << "Array: [" << arr[0] << ", " << arr[1] << "]\n";
    int* p1 = arr;
    int (*p2)[2] = &arr;
    cout << "p1 is a pointer to int (points to first element)\n";
    cout << "p2 is a pointer to array of 2 ints (points to entire array)\n";
    cout << "p1 points to int: *p1 = " << *p1 << "\n";
    cout << "p2 points to array: *(*p2) = " << *(*p2) << " (dereferencing twice)\n";
    cout << "Both access the same value but represent different pointer types\n";
}

void trick4() {
    cout << "\n🔹 Trick 4: Printing memory addresses of array elements\n";
    int arr[3] = {1, 2, 3};
    cout << "Array: [" << arr[0] << ", " << arr[1] << ", " << arr[2] << "]\n";
    cout << "Memory addresses of each element:\n";
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] (value " << arr[i] << ") is at address: " << (void*)&arr[i] << "\n";
    }
    cout << "Notice how addresses increase by " << sizeof(int) << " bytes (size of int)\n";
}

void trick5() {
    cout << "\n🔹 Trick 5: Calculating byte offset between two elements\n";
    int arr[2] = {100, 200};
    cout << "Array: [" << arr[0] << ", " << arr[1] << "]\n";
    cout << "Address of arr[0]: " << (void*)&arr[0] << "\n";
    cout << "Address of arr[1]: " << (void*)&arr[1] << "\n";
    uintptr_t diff = (uintptr_t)&arr[1] - (uintptr_t)&arr[0];
    cout << "Byte difference between arr[1] and arr[0]: " << diff << " bytes\n";
    cout << "This equals sizeof(int) = " << sizeof(int) << " bytes\n";
}

void trick6() {
    cout << "\n🔹 Trick 6: *(arr + i) vs arr[i] - Two ways to access same element\n";
    int arr[4] = {4, 5, 6, 7};
    cout << "Array: [" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << "]\n";
    cout << "Demonstrating that arr[i] and *(arr + i) are equivalent:\n";
    for (int i = 0; i < 4; ++i)
        cout << "arr[" << i << "] = " << arr[i] << " | *(arr + " << i << ") = " << *(arr + i) << " (same value)\n";
}

void trick7() {
    cout << "\n🔹 Trick 7: Creating a mini dynamic array manually\n";
    cout << "Allocating memory for 3 integers on the heap\n";
    int* arr = new int[3]{100, 200, 300};
    cout << "Dynamic array created: [" << arr[0] << ", " << arr[1] << ", " << arr[2] << "]\n";
    cout << "Accessing third element using pointer arithmetic:\n";
    cout << "*(arr + 2) = " << *(arr + 2) << " (third element)\n";
    cout << "Freeing allocated memory...\n";
    delete[] arr;
    cout << "Memory successfully freed\n";
}

void trick8() {
    cout << "\n🔹 Trick 8: Reverse array using pointers\n";
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Original array: [";
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
        if (i < 4) cout << ", ";
    }
    cout << "]\n";
    
    cout << "Reversing using two pointers (start and end):\n";
    int* start = arr;
    int* end = arr + 4;
    while (start < end) {
        cout << "Swapping " << *start << " and " << *end << "\n";
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    cout << "Reversed array: [";
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
        if (i < 4) cout << ", ";
    }
    cout << "]\n";
}

void trick9() {
    cout << "\n🔹 Trick 9: Pointer arithmetic with char array\n";
    char str[] = "Hello";
    cout << "String: \"" << str << "\"\n";
    cout << "Traversing character by character using pointer:\n";
    char* ptr = str;
    cout << "Characters: ";
    while (*ptr) {
        cout << "'" << *ptr << "' ";
        ptr++;
    }
    cout << "\nPointer increments through each character until null terminator\n";
}

void trick10() {
    cout << "\n🔹 Trick 10: Using pointer to step over even indices only\n";
    int arr[6] = {10, 20, 30, 40, 50, 60};
    cout << "Array: [" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", " << arr[5] << "]\n";
    cout << "Accessing only even indices (0, 2, 4) using pointer arithmetic:\n";
    cout << "Elements at even indices: ";
    for (int* p = arr; p < arr + 6; p += 2) {
        cout << *p << " ";
    }
    cout << "\nPointer increments by 2 each time (skipping odd indices)\n";
}

int main() {
    string input;

    while (true) {
        cout << "\nEnter a number (1-10) to run a trick, or 'q' to quit: ";
        cin >> input;

        if (input == "q") {
            cout << "Exiting...\n";
            break;
        }

        try {
            int choice = stoi(input);
            switch (choice) {
                case 1: trick1(); break;
                case 2: trick2(); break;
                case 3: trick3(); break;
                case 4: trick4(); break;
                case 5: trick5(); break;
                case 6: trick6(); break;
                case 7: trick7(); break;
                case 8: trick8(); break;
                case 9: trick9(); break;
                case 10: trick10(); break;
                default:
                    cout << "❌ Not a valid command.\n";
            }
        } catch (...) {
            cout << "❌ Not a valid command.\n";
        }
    }

    return 0;
}