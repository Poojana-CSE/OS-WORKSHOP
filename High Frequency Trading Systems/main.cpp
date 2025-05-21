// // High - Frequency Trading Systems: Microsecond - level latency requires lock free data structure to handle thounsands of trade per second
// #include <iostream>
// #include <thread>
// #include <atomic>
// #include <vector>
// using namespace std;
// #define MAX_TRADES 5
// atomic<int> available_trades(MAX_TRADES);

// void execute_trade(int user_id) {
//     int current;
//     do {
//         current = available_trades.load();
//         if (current <= 0) {
//             cout << "User id " << user_id << ": No trades available\n";
//             return;
//         }
//     } while (!available_trades.compare_exchange_weak(current, current - 1));
//     cout << "User id " << user_id << " executed a trade\n";
// }

// int main() {
//     vector<thread> users;

//     for (int i = 0; i < 10; ++i) {
//         users.emplace_back(execute_trade, i + 1);
//     }

//     for (auto& user : users) {
//         user.join();
//     }

//     return 0;
// }







// Lambda functions
    // [] -> captures
        // [=] -> capture by value
        // [&] -> capture by reference
        // []  -> without captures (other than lambda functions other variabls from outside cannot be accessed)
    // Syntax:
        // auto var = [](arguments){
        //     return statement;
        // };


#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

struct Node {
    int value;
    Node* next;
};

// Atomic pointer to the head of the stack
atomic<Node*> head(nullptr);

void push(int val) {
    Node* newNode = new Node();
    newNode->value = val;
    do {
        newNode->next = head.load();
    } while (!head.compare_exchange_weak(newNode->next, newNode));
}

int pop() {
    Node* oldHead;
    do {
        oldHead = head.load();
        if (!oldHead)
            return -1;
    } while (!head.compare_exchange_weak(oldHead, oldHead->next));

    int val = oldHead->value;
    delete oldHead;
    return val;
}

int main() {
    thread t1([]() {
        for (int i = 0; i < 10; i++)
            push(i);
    });

    thread t2([]() {
        for (int i = 10; i < 20; i++)
            push(i);
    });

    t1.join();
    t2.join();

    for (int i = 0; i < 20; i++) {
        int val = pop();
        if (val != -1)
            cout << val << " ";
        else
            cout << "Stack empty\n";
    }
    cout << endl;
    return 0;
}


