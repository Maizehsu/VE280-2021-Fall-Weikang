/*
 * @Author: Maize
 * @Date: 2021-11-28 10:56:40
 * @LastEditTime: 2021-12-09 14:11:08
 * @Description: VE280 2021 Fall Project 5 RPN Calculator
 * @FilePath: \p5\calc.cpp
 */

#include "dlist.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// MODIFIES: stack
// EFFECTS: Apply operands involving two numbers.
void twoOperand(char c, Dlist<int> *stack) {
    int *temp1, *temp2;
    if (stack->isEmpty())
        cout << "Not enough operands\n";
    else {
        temp1 = stack->removeFront();
        if (stack->isEmpty()) {
            cout << "Not enough operands\n";
            stack->insertFront(temp1);
        } //Insert temp1 back to the stack.
        else {
            temp2 = stack->removeFront();
            switch (c) {
            case '+':
                *temp2 = *temp2 + *temp1;
                stack->insertFront(temp2);
                delete temp1;
                break;
            case '-':
                *temp2 = *temp2 - *temp1;
                stack->insertFront(temp2);
                delete temp1;
                break;
            case '*':
                *temp2 = *temp1 * *temp2;
                stack->insertFront(temp2);
                delete temp1;
                break;
            case '/':
                if (*temp1 == 0) {
                    stack->insertFront(temp2);
                    stack->insertFront(temp1);
                    cout << "Divide by zero\n";
                }
                else {
                    *temp2 = *temp2 / *temp1;
                    stack->insertFront(temp2);
                    delete temp1;
                }
                break;
            case 'r':
                stack->insertFront(temp1);
                stack->insertFront(temp2);
                break;
            default:
                delete temp1;
                delete temp2;
                break;
            }
        }
    }
}

// MODIFIES: stack
// EFFECTS: Apply operands involving one number.
void oneOperand(char c, Dlist<int> *stack) {
    int *temp;
    // Always check for input errors first.
    if (stack->isEmpty())
        cout << "Not enough operands\n";
    else {
        temp = stack->removeFront();
        switch (c) {
        case 'n':
            *temp = *temp * (-1);
            stack->insertFront(temp);
            break;
        case 'd':
            stack->insertFront(temp);
            stack->insertFront(new int(*temp));
            break;
        case 'p':
            cout << *temp << endl;
            stack->insertFront(temp);
            break;
        default:
            delete temp;
            break;
        }
    }
}

// MODIFIES: stack
// EFFECTS: Clear the stack.
void clearStack(Dlist<int> *stack) {
    while (!(stack->isEmpty())) {
        delete (stack->removeFront());
    }
}

// MODIFIES: stack
// EFFECTS: Print all items of the stack.
void printStack(Dlist<int> *stack) {
    Dlist<int> temp(*stack);
    while (!temp.isEmpty()) {
        int *val = temp.removeFront();
        cout << *val << " ";
        delete val;
    }
    cout << endl;
}

// MODIFIES: stack
// EFFECTS: Insert an integer into the stack.
void insertInt(string input, Dlist<int> *stack) {
    int sign = 1, value = 0;
    for (int i = 0; i < (int)input.length(); i++) {
        if (i == 0 && input[i] == '-') {
            sign = -1;
            continue;
        }
        int digit = input[i] - '0';
        value = value * 10 + digit;
    }
    int *result = new int(sign * value);
    stack->insertFront(result);
}

// EFFECTS: Check whether an input string is a valid integer.
bool checkInt(string input) {
    for (int i = 0; i < (int)input.length(); i++) {
        // It's OK to have '-' at the beginning.
        if (i == 0 && input[i] == '-' && input.length() > 1) continue;
        if (input[i] > '9' || input[i] < '0') {
            return false;
        }
    }
    return true;
}

// MODIFIES: stack
// EFFECTS: Check input and apply respective functions according to the input.
bool checkInput(string input, Dlist<int> *stack) {
    if (checkInt(input)) {
        insertInt(input, stack);
        return true;
    } // First check if the input is an integer.
    if (input.length() > 1) {
        cout << "Bad input\n";
        return true;
    }
    switch (input[0]) {
    case 'q': return false;
    case '+':
    case '-':
    case '*':
    case '/':
    case 'r':
        twoOperand(input[0], stack);
        return true;
    case 'n':
    case 'd':
    case 'p':
        oneOperand(input[0], stack);
        return true;
    case 'c':
        clearStack(stack);
        return true;
    case 'a':
        printStack(stack);
        return true;
    default:
        cout << "Bad input\n";
        return true;
    }
}

int main() {
    string input;
    Dlist<int> *stack = new Dlist<int>;
    cin >> input;
    while (checkInput(input, stack))
        cin >> input;
    delete stack;
    return 0;
}