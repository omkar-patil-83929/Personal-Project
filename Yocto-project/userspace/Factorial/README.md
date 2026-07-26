# Factorial - Userspace Application

## Overview

This project demonstrates the development of a simple command-line userspace application in C and its integration into the Yocto Project using a custom BitBake recipe.

The application accepts an integer as a command-line argument and calculates its factorial. It serves as a basic example of packaging a custom userspace application for an embedded Linux system.

---

## Features

- Written in C
- Command-line argument based input
- Calculates factorial of a positive integer
- Custom BitBake recipe for Yocto
- Suitable for integration into a custom Yocto image

---

## Project Structure

```
Factorial/
├── factorial.c
├── factorial.bb
└── README.md
```

---

## Files

 factorial.c : Source code for the factorial application.
 factorial.bb : BitBake recipe used to build and package the application. 
 README.md : Project documentation. 

---

## Prerequisites

- GCC Compiler
- Yocto Project Build Environment
- BitBake

---

## Building the Application

Compile using GCC:

```bash
gcc factorial.c -o factorial
```

---

## Running the Application

### Syntax

```bash
./factorial <positive_integer>
```

### Example

```bash
./factorial 5
```

### Sample Output

```text
Factorial of 5 is 120
```

---

## BitBake Recipe

The application is packaged using a custom BitBake recipe.

Build the package using:

```bash
bitbake factorial
```

The generated package can then be included in a custom Yocto image.

---

## Learning Outcomes

This project demonstrates:

- Userspace application development in C
- Command-line argument handling using `argc` and `argv`
- Custom BitBake recipe creation
- Packaging applications in Yocto
- Embedded Linux application integration

---

## Future Enhancements

- Improve input validation
- Detect integer overflow
- Add Makefile support
- Integrate into a custom Yocto image
- Add automated test cases

---

## Repository Structure

```
Personal-Project/
└── Yocto-Project/
    └── userspace/
        └── Factorial/
            ├── factorial.c
            ├── factorial.bb
            └── README.md
```

---

## Author

Omkar Patil

Embedded Linux | Yocto | Linux Device Drivers | C Programming

---

## License

This project is intended for learning, experimentation, and educational purposes.