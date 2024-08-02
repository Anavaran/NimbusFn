// NimbusFn_Server.cpp : Defines the entry point for the application.
//

#include "NimbusFn_Server.h"

int main() {
    try {
        // Machine code for a function that adds two integers (x64 assembly)
        // int add(int a, int b) { return a + b; }
        std::vector<unsigned char> code = {
            0x55, 0x89, 0xE5, 0x8B, 0x45, 0x08, 0x03, 0x45, 0x0C, 0x5D, 0xC2, 0x00, 0x00
        };

        // Allocate executable memory
        void* exec_mem;
#if defined(_WIN32) || defined(_WIN64)
        exec_mem = VirtualAlloc(NULL, code.size(), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
#else
        exec_mem = mmap(NULL, code.size(), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
#endif

        if (exec_mem == nullptr) {
            throw std::runtime_error("Failed to allocate executable memory");
        }

        // Copy the machine code to the executable memory
        std::memcpy(exec_mem, code.data(), code.size());
        std::cout << "hello" << '\n';
        // Cast the memory address to a function pointer
        // Note: This function takes two int parameters and returns an int
        int (*add_func)(int, int) = reinterpret_cast<int(*)(int, int)>(exec_mem);

        // Call the function
        int result = add_func(5, 7);
        std::cout << "Result of 5 + 7: " << result << std::endl;

        // Free the executable memory
#if defined(_WIN32) || defined(_WIN64)
        if (!VirtualFree(exec_mem, 0, MEM_RELEASE)) {
            throw std::runtime_error("Failed to free executable memory");
        }
#else
        if (munmap(exec_mem, code.size()) != 0) {
            throw std::runtime_error("Failed to free executable memory");
        }
#endif

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}