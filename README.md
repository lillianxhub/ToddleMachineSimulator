# Toddler Machine Simulator Tutorial

This tutorial will guide you through setting up and using a Toddler machine simulator written in C++. You'll learn how to compile the program, write Toddler machine code, and simulate its execution.

## Prerequisites

- Basic understanding of C++ programming.
- A C++ compiler (e.g., `g++`).
- A text editor to write Toddler machine programs.

## Step 1: Writing a Toddler Machine Program

First, you'll need to write a program for the Toddler machine. Here's a simple example program that adds two numbers and outputs the result.

Create a new text file named `program.td` and add the following lines:

```
(01) +850 INPUT 50
(02) +851 INPUT 51
(03) +150 LOAD 50
(04) +351 ADD 51
(05) +252 STORE 52
(06) +952 OUTPUT 52
(07) +500 HALT
```

Save this file as `program.td`.

## Step 2: Compiling the Simulator

Now, let's compile the simulator program. Assuming you have the source code for the simulator saved as `toddler_simulator.cpp`, follow these steps:

1. Open a terminal or command prompt.
2. Navigate to the directory where `toddler_simulator.cpp` is located.
3. Compile the program using `g++`:

    ```bash
    g++ -o toddler_simulator toddler_simulator.cpp
    ```

This command will create an executable file named `toddler_simulator`.

## Step 3: Running the Simulator

To run the simulator:

1. Ensure that your Toddler machine program file (`program.td`) is in the same directory as the compiled simulator.
2. In the terminal, run the simulator:

    ```bash
    ./toddler_simulator
    ```

3. When prompted, enter the file name of the Toddler machine program:

    ```plaintext
    Enter the file name of the Toddler machine program: program.td
    ```

4. Follow the on-screen instructions. The simulator will execute your program, performing input/output operations and displaying the results.

### Example Run:

```plaintext
Enter the file name of the Toddler machine program: program.td
Enter a value: 3
Enter a value: 4
Output: 7
Program halted.
```

In this example, the program adds 3 and 4, then outputs the result, 7.

## Step 4: Extending the Simulator

You can extend the simulator by adding more instructions, handling stack operations, or implementing advanced features like function calls. Modify the `executeInstruction` function in the C++ code to add new functionalities.

## Step 5: Debugging and Testing

To debug or test your simulator, you can use the `printMemory` function to dump the memory contents at various stages of execution. This can help identify issues or verify the correctness of your implementation.

## Program Structure
A Toddler machine program consists of a sequence of instructions, where each instruction has a specific format:

+ Label (Optional) :(xx) A label for the instruction, enclosed in parentheses. Labels are optional and are typically used to mark specific instructions for reference (e.g., jump targets).
+ Instruction: (+xxx) The actual command to be executed, represented as a three-digit number.
+ Comment (Optional): ( ; Comment ) A comment explaining the instruction, starting with a semicolon.

```
(xx) +xxx ; comment
```
## Checklist

- [ ] Basic Intruction
- [ ] Jump feature
- [ ] Exended Intruction
- [ ] Stack support