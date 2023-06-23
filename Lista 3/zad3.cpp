#include <iostream>

struct Link {

    int value;
    Link* next = nullptr;
};

void release(Link** phead) {
    
    Link* head = *phead;
    
    if (head == nullptr) return;

    Link* next = head -> next;
    delete head;
    *phead = nullptr;
    
    release(&next);
}

void reverse(Link** head) {

    Link* prevElement = nullptr;
    Link* currentElement = *head;
    Link* nextElement = nullptr;

    while (currentElement != nullptr) {
        nextElement = currentElement -> next;
        currentElement -> next = prevElement;
        prevElement = currentElement;
        currentElement = nextElement;
    }

    *head = prevElement;
}

int main() {

    Link* head = new Link{0};
    head -> next = new Link{1};
    head -> next -> next = new Link{2};

    head -> value = 15;
    head -> next -> value = 9;
    head -> next -> next -> value = 4;

    std::cout << "Starting list: [0]: 15 - [1]: 9 - [2]: 4\n";
    reverse(&head);
    std::cout << "Reversed list: ";
    
    int index = 0;

    while (head != nullptr) {
        if (head -> next == nullptr)
            std::cout << "[" << index << "]: " << head -> value << "\n";
        else 
            std::cout << "[" << index << "]: " << head -> value << " - ";

        head = head -> next;
        index++;
    }

    release(&head);

    return 0;
}