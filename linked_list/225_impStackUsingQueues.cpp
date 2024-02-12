#include <queue>

using namespace std;

class MyException : public std::exception {
public:
    // Constructor with a custom error message
    MyException(const char* message) : m_message(message) {}

    // Override the what() function to return the error message
    const char* what() const noexcept override {
        return m_message;
    }

private:
    const char* m_message;
};

class MyStack {
public:
    queue<int> mutantStack;
    // queue<int> tempholder;

    MyStack() {
        
    }
    
    void push(int x) {
        mutantStack.push(x);
    }
    
    int pop() {
        // Do I have to consider the edge case when size = 0?
        if (mutantStack.size() == 0)
            throw MyException("Error: the stack is empty");

        // Traverse till the last element
        for (int i = 0; i < mutantStack.size() - 1; ++i) {
            mutantStack.push(mutantStack.front());
            mutantStack.pop();
        }

        // Return the now the first element of mutant
        int returner = mutantStack.front();
        mutantStack.pop();
        return (returner);
    }
    
    int top() {
        return (mutantStack.back());
    }
    
    bool empty() {
        return (mutantStack.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */