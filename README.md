# Infinite Digits

## Description
**Infinite Digits** is a C++ program that implements a custom **LongInt** class to handle large integer arithmetic. It uses a doubly linked list to represent arbitrarily large numbers, allowing addition operations beyond the typical integer limits of C++.

## Features
- Stores large integers using a doubly linked list.
- Supports user input for large numbers.
- Implements addition for large integers.
- Automatically removes leading zeros from results.

## How It Works
1. The user inputs two large integers.
2. The program converts the input into a **LongInt** object.
3. The two numbers are added using a custom addition function.
4. The result is displayed, maintaining correct digit order.

## Example Usage
```bash
$ ./infinite_digits
-> 12345678901234567890
-> 98765432109876543210
-----
111111111011111111100
```

## Installation & Usage
### Prerequisites
- A C++ compiler (e.g., g++, Clang, MSVC)

### Compilation
Compile the program using g++:
```bash
g++ -o infinite_digits main.cpp
```

### Running the Program
```bash
./infinite_digits
```
Then, enter two large integers when prompted.

## Code Structure
- `LongInt`: A class that stores large integers as a doubly linked list.
- `zeroStrip()`: Removes leading zeros from the number.
- `inputLongInt()`: Reads user input and stores it in a **LongInt** object.
- `addLongInt()`: Performs addition of two **LongInt** objects.
- `printLongInt()`: Prints the result of a **LongInt** object.
- `main()`: Handles user input and displays the result.

## Future Improvements
- Implement subtraction, multiplication, and division.
- Optimize memory usage and performance.
- Add support for negative numbers.

## License
This project is open-source and available under the MIT License.

