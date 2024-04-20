#include <iostream>
#include <limits>
using namespace std;

bool isProgramRunning = true;

// STACK VARIABLES
const int maxStackSize = 5;
int stackList[maxStackSize];
int topIndex = -1;

// CIRCULAR QUEUE VARIABLES
const int maxCQueueSize = 5;
int cQueueList[maxCQueueSize];
int cQueueSize = 0;
int frontIndex = -1;
int rearIndex = -1;

// DISPLAY OPERATIONS
void printStackOperations(){
    cout << "Select which operation you want to perform." << endl;
    cout << "[1] Push" << endl;
    cout << "[2] Pop" << endl;
    cout << "[3] isEmpty()" << endl;
    cout << "[4] isFull()" << endl;
    cout << "[5] peek()" << endl;
    cout << "[6] count()" << endl;
    cout << "[7] -Clear" << endl;
    cout << "[0] EXIT" << endl;
}

void printCQueueOperations(){
    cout << "Select which operation you want to perform." << endl;
    cout << "[1] Enqueue" << endl;
    cout << "[2] Dequeue" << endl;
    cout << "[3] isEmpty()" << endl;
    cout << "[4] isFull()" << endl;
    cout << "[5] peek()" << endl;
    cout << "[6] count()" << endl;
    cout << "[0] EXIT" << endl;
}


// STACK OPERATIONS
bool isStackEmpty(){
    return topIndex == -1;
}

bool isStackFull(){
    return topIndex == maxStackSize - 1;
}

void push(int item){
    if(isStackFull()){
        cout << "STACK IS FULL! Cannot push anymore!" << endl;
    }else{
        stackList[++topIndex] = item;
        cout << "You pushed the value: " << item << endl;
    }
}

void pop(){
    if(isStackEmpty()){
        cout << "STACK IS EMPTY... Cannot pop any item." << endl;
    }else{
        int poppedItem = stackList[topIndex--];
        cout << "The item " << poppedItem << " has been popped from the stack!" << endl;
    }
}

int peekStack(){
    if(isStackEmpty()){
        cout << "STACK IS EMPTY... Cannot pop any item." << endl;
        return -1;
    }else{
        return stackList[topIndex];
    }
}

int stackCount(){
    return topIndex + 1;
}

void stackClear(){
    topIndex = -1;
    cout << "Stack is cleared!" << endl;
}

void printLatestStack(){
    cout << "All values in the stack are:" << endl;
    for(int i = maxStackSize - 1; i >= 0; --i){
            cout << "| ";
            if (i <= topIndex) {
                cout << stackList[i];
            }else{
                cout << "0";
            }
            cout << " |" << endl;
    }
}

// CIRCULAR QUEUE OPERATIONS
bool isCQueueEmpty(){
    return cQueueSize == 0;
}

bool isCQueueFull(){
    return cQueueSize == maxCQueueSize;
}

void enqueue(int item){
    if(isCQueueFull()){
        cout << "QUEUE IS FULL! Cannot enqueue anymore!" << endl;
    }else{
        if(frontIndex == -1){
            frontIndex = 0;
        }
        rearIndex = (rearIndex + 1) % maxCQueueSize;
        cQueueList[rearIndex] = item;
        cQueueSize++;
        cout << "You enqueued the value: " << item << endl;
    }
}

void dequeue(){
    if(isCQueueEmpty()){
        cout << "QUEUE IS EMPTY... Cannot dequeue any item." << endl;
    }else{
        int poppedItem = cQueueList[frontIndex];
        cQueueList[frontIndex] = 0;
        cQueueSize--;
        int nextFrontIndex = (frontIndex + 1) % maxCQueueSize;
        while(cQueueList[nextFrontIndex] == -1 && nextFrontIndex != rearIndex){
            nextFrontIndex = (nextFrontIndex + 1) % maxCQueueSize;
        }
        frontIndex = nextFrontIndex;
        cout << "The item " << poppedItem << " has been popped from the stack!" << endl;
    }
}

int peekCQueue(){
    if(isCQueueEmpty()){
        return -1;
    }else{
        return cQueueList[frontIndex];
    }
}

int cQueueCount(){
    return cQueueSize;
}

void printCQueue(){
    cout << "All values in the circular queue are:" << endl;
    for(int i = 0; i < maxCQueueSize; i++){
        cout << "|" << cQueueList[i] << "| ";
    }
    cout << endl;
}

/////// MAIN PROGRAM OPERATIONS ///////
void printDataStructureOption(){
    cout << "Enter [1] for stack list or [2] for circular queue" << endl;
}

int getUserInput(){
    int userInput;
    while (!(cin >> userInput)) {
        cout << "INVALID INPUT!!! Please enter a number!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return userInput;
}

// STACK OPERATION SELECTOR
void stackOperationSelect(int userInput){
    switch(userInput){
        case 0:
            isProgramRunning = false;
            cout << "Ending program." << endl;
            break;
        case 1:
            cout << "You selected PUSH operation." << endl;
            cout << "Enter a number to add to the stack." << endl;
            int item;
            item = getUserInput();
            push(item);
            printLatestStack();
            break;
        case 2:
            cout << "You selected POP operation." << endl;
            pop();
            printLatestStack();
            break;
        case 3:
            cout << "You selected isEmpty operation." << endl;
            if(isStackEmpty()){
                cout << "Stack is empty!" << endl;
            }else{
                cout << "Stack is not empty!" << endl;
            }
            printLatestStack();
            break;
        case 4:
            cout << "You selected isFull operation." << endl;
            if(isStackFull()){
                cout << "Stack is full!" << endl;
            }else{
                cout << "Stack is not full!" << endl;
            }
            printLatestStack();
            break;
        case 5:
            cout << "You selected PEEK operation." << endl;
            cout << "The top element is: " << peekStack() << endl;
            printLatestStack();
            break;
        case 6:
            cout << "You selected COUNT operation." << endl;
            cout << "There are " << stackCount() << " in the stack." << endl;
            printLatestStack();
            break;
        case 7:
            cout << "You selected CLEAR operation." << endl;
            stackClear();
            printLatestStack();
            break;
        default:
            cout << "ERROR! ENTER AN INTEGER!" << endl;
    }
}

// CIRCULAR QUEUE OPERATION SELECTOR
void cQueueOperationSelect(int userInput){
    switch(userInput){
        case 0:
            isProgramRunning = false;
            cout << "Ending program." << endl;
            break;
        case 1:
            cout << "You selected ENQUEUE operation." << endl;
            cout << "Enter a number to add to the queue." << endl;
            int item;
            item = getUserInput();
            enqueue(item);
            printCQueue();
            break;
        case 2:
            cout << "You selected DEQUEUE operation." << endl;
            dequeue();
            printCQueue();
            break;
        case 3:
            cout << "You selected isEmpty operation." << endl;
            if(isCQueueEmpty()){
                cout << "Queue is empty!" << endl;
            }else{
                cout << "Queue is not empty!" << endl;
            }
            printCQueue();
            break;
        case 4:
            cout << "You selected isFull operation." << endl;
            if(isCQueueFull()){
                cout << "Queue is full!" << endl;
            }else{
                cout << "Queue is not full!" << endl;
            }
            printCQueue();
            break;
        case 5:
            cout << "You selected PEEK operation." << endl;
            cout << "The top element is: " << peekCQueue() << endl;
            printCQueue();
            break;
        case 6:
            cout << "You selected COUNT operation." << endl;
            cout << "There are " << cQueueCount() << " in the queue." << endl;
            printCQueue();
            break;
        default:
            cout << "ERROR! ENTER AN INTEGER!" << endl;
    }
}


//// MAIN METHOD ////
int main()
{
    printDataStructureOption();
    switch(getUserInput()){
        case 1:
            do{
                printStackOperations();
                stackOperationSelect(getUserInput());
            }while(isProgramRunning);
            break;
        case 2:
            do{
                printCQueueOperations();
                cQueueOperationSelect(getUserInput());
            }while(isProgramRunning);
            break;
        default: cout << "invalid" << endl;
    }
    return 0;
}
