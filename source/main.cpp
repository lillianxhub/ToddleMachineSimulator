#include <iostream>
#include <array>
#include <fstream>
#include <sstream>

// Constants
const int MEMORY_SIZE = 100;
const int STACK_START = 99;

// Memory and Registers
std::array<int, MEMORY_SIZE> memory = {0};
int AC = 0;           // Accumulator
int PC = 0;           // Program Counter
int IR = 0;           // Instruction Register
int SP = STACK_START; // Stack Pointer

// Function Prototypes
void loadProgram(const std::string &filename);
void run();
void fetch();
void decodeAndExecute();
void executeInstruction(int opcode, int address);
void printMemory();

int main()
{
    std::string programFile;

    // User input for Toddler machine program file
    std::cout << "Enter the file name of the Toddler machine program: ";
    std::cin >> programFile;

    // Load the program into memory
    loadProgram(programFile);

    // Simulate execution
    run();

    return 0;
}

// Load program from a file
void loadProgram(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    int address = 0;

    while (std::getline(file, line) && address < MEMORY_SIZE)
    {
        std::istringstream iss(line);
        int instruction;
        if (iss >> instruction)
        {
            memory[address++] = instruction;
        }
    }

    std::cout << "Program loaded into memory." << std::endl;
}

// Simulate execution cycle
void run()
{
    while (true)
    {
        fetch();
        decodeAndExecute();
    }
}

// Fetch the current instruction
void fetch()
{
    IR = memory[PC++];
}

// Decode and execute the current instruction
void decodeAndExecute()
{
    int opcode = IR / 100;
    int address = IR % 100;

    executeInstruction(opcode, address);
}

// Execute the instruction based on opcode
void executeInstruction(int opcode, int address)
{
    switch (opcode)
    {
    case 1: // LOAD
        AC = memory[address];
        break;
    case 2: // STORE
        memory[address] = AC;
        break;
    case 3: // ADD
        AC += memory[address];
        break;
    case 4: // SUB
        AC -= memory[address];
        break;
    case 5: // HALT
        std::cout << "Program halted." << std::endl;
        exit(0);
    case 8: // INPUT
        std::cout << "Enter a value: ";
        std::cin >> memory[address];
        break;
    case 9: // OUTPUT
        std::cout << "Output: " << memory[address] << std::endl;
        break;
    // Implement other instructions here
    default:
        std::cerr << "Invalid opcode!" << std::endl;
        exit(1);
    }
}

// Optional: Print the memory contents for debugging
void printMemory()
{
    std::cout << "Memory Dump:" << std::endl;
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        std::cout << i << ": " << memory[i] << std::endl;
    }
}