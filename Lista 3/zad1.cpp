#include <iostream>

struct Link {

    int value;
    Link* next = nullptr;
};

size_t size(const Link* head) {
        
    const Link* current = head;
    size_t res = 0;
    
    while (current != nullptr) {
        res++;
        current = current -> next;
    }
        
    return res;
}

size_t sum(const Link* head) {

    size_t res = 0;
    const Link* element = head;

    while (element != nullptr)
    {
        res += element -> value;
        element = element -> next;
    }

    return res;
}

int main() {
    
    Link* head = new Link{1};
    head -> next = new Link{2};
    head -> next -> next = new Link{3};
    head -> value = 4;
    head -> next -> value = 5;
    head -> next -> next -> value = 8;
    size_t listSize = size(head);
    std::cout << listSize << "\n";
    size_t elementsSum = sum(head);
    std::cout << elementsSum;

    return 0;
}