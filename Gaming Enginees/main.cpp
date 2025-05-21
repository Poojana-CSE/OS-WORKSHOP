#include <iostream>
#include <vector>
using namespace std;
const int pool_size = 1024;

class MemoryPool {
    char pool[pool_size];
    vector<bool> used;

public:
    MemoryPool() {
        used.resize(pool_size, false);
    }

    void* allocate(int size) {
        for (int i = 0; i <= pool_size - size; i++) {
            bool canAllocate = true;
            for (int j = i; j < i + size; j++) {
                if (used[j]) {
                    canAllocate = false;
                    break;
                }
            }
            if (canAllocate) {
                for (int j = i; j < i + size; j++) {
                    used[j] = true;
                }
                return (void*)&pool[i];
            }
        }
        cout << "Allocation failed!\n";
        return nullptr;
    }

    void deallocate(void* ptr, int size) {
        int index = (char*)ptr - pool;
        if (index < 0 || index + size > pool_size) {
            cout << "Invalid deallocation request!\n";
            return;
        }
        for (int i = index; i < index + size; i++) {
            used[i] = false;
        }
        cout << "Memory deallocated successfully.\n";
    }
};

int main() {
    MemoryPool mp;
    void* block = mp.allocate(100);
    if (block != nullptr) {
        cout << "Allocated 100 bytes successfully.\n";
    }
    mp.deallocate(block, 100);
    return 0;
}