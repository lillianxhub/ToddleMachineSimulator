#include <iostream>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

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

    // Regular expressions to extract instructions and variable assignments
    std::regex instructionRegex(R"((?:\(\d+\))?\s*\+?(\d+))");
    std::regex variableRegex(R"(\+0(\d{2})\s+(\d+))");

    while (std::getline(file, line) && address < MEMORY_SIZE)
    {
        std::smatch match;
        if (std::regex_search(line, match, variableRegex))
        {
            int varAddress = std::stoi(match[1].str());
            int varValue = std::stoi(match[2].str());
            memory[varAddress] = varValue;
        }
        else if (std::regex_search(line, match, instructionRegex))
        {
            int instruction = std::stoi(match[1].str());
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
    case 5: // JUMP
        PC = address;
        break;
    case 6: // JUMPZ
        if (AC == 0)
        {
            PC = address;
        }
        break;
    case 7: // JUMPN
        if (AC < 0)
        {
            PC = address;
        }
        break;
    case 8: // INPUT
        std::cout << "Enter a value: ";
        std::cin >> memory[address];
        break;
    case 9: // OUTPUT
        std::cout << "Output: " << memory[address] << std::endl;
    case 500: // HALT
        std::cout << "Program halted." << std::endl;
        exit(0);
    default:
        std::cerr << "Invalid opcode!" << std::endl;
        exit(1);
    }
}

// Function to print the memory (optional, for debugging)
void printMemory()
{
    for (int i = 0; i < MEMORY_SIZE; ++i)
    {
        std::cout << "Address " << i << ": " << memory[i] << std::endl;
    }
}
