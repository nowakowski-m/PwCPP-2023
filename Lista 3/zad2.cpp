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

int main() {

    Link* phead = new Link{1}; 
    release(&phead);

    return 0;
}