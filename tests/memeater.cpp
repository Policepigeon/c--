#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    std::vector<char*> memoryBlocks;
    size_t blockSize = 1024 * 1024; // 1 MB block size
    bool keepAllocating = true;

    while (keepAllocating) {
        try {
            char* block = new char[blockSize];
            memoryBlocks.push_back(block);
            std::cout << "Allocated " << (memoryBlocks.size() * blockSize / (1024 * 1024)) << " MB" << std::endl;
        } catch (std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            keepAllocating = false;
        }
    }

    // Clean up allocated memory
    for (char* block : memoryBlocks) {
        delete[] block;
    }

    std::cout << "Memory successfully deallocated." << std::endl;
    /* i should modify this so that it can be used to ensure users in my nea do not exceed the memory requirements of the system*/
    return 0;
}
