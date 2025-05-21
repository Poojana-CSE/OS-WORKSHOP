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
        for (int i = index; i < index + size; i++) {
            used[i] = false;
        }
        cout << "Memory deallocated successfully.\n";
    }
};

int main() {
    MemoryPool mp;
    void* block = mp.allocate(128);
    cout<<"Memory Loaded\n";
    void* block = mp.allocate(256);
    cout<<"Memory Loaded\n";
    mp.deallocate(block, 128);
    cout<<"Memory Unloaded\n";
    return 0;
}