# Prime Number / Number Theory Toolkit

A simple C++ number theory toolkit built for competitive programming practice.

## Features

- Prime checking
- Prime generation using Sieve of Eratosthenes
- Prime factorization
- GCD and LCM calculation
- Modular exponentiation

## Why this project?

This project is useful for competitive programming because it combines common number theory operations in one clean, reusable C++ program. It is also a good practice project for learning logic, loops, functions, and optimization basics.

## Requirements

- C++17 or later
- A C++ compiler like `g++`, `clang++`, or MSVC

## How to Compile

```bash
g++ -std=c++17 main.cpp -o toolkit
```

## How to Run

```bash
./toolkit
```

On Windows:

```bash
toolkit.exe
```

## Example Usage

### 1. Check if a number is prime
Enter a number and the program will tell you whether it is prime or not.

### 2. Generate primes
Use the sieve option to generate all prime numbers up to a given limit.

### 3. Factorize a number
The program gives the prime factorization in exponent form.

### 4. Find GCD and LCM
Enter two numbers to compute their GCD and LCM.

### 5. Modular exponentiation
Compute:

\[
(base^{exponent}) \bmod mod
\]

efficiently using fast power.

## Project Structure

```bash
main.cpp
README.md
```

## Future Improvements

- Add segmented sieve
- Add Euler’s totient function
- Add modular inverse
- Add interactive command-line arguments
- Split code into multiple files for better structure

## License

Free to use for learning and personal projects.
