#include <iostream>
#include <type_traits>
#include <string>

template<typename T> //template with declared type T
class flist { //implementing class
private:
    struct Link {
        T value;
        Link* next = nullptr;
    };

    Link* head = nullptr;

    void release() {
        Link* current = head;

        while (current != nullptr) {
            Link* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }

    void copy(const flist& other) {
        Link* current = other.head;
        Link* newHead = nullptr;
        Link* newTail = nullptr;

        while (current != nullptr) {
            Link* newElement = new Link{ current->value };
            if (newHead == nullptr) {
                newHead = newElement;
                newTail = newElement;
            } 
            
            else {
                newTail->next = newElement;
                newTail = newElement;
            }

            current = current->next;
        }

        head = newHead;
    }

public:
    // copying constructor
    flist(const flist& other) {
        copy(other);
    }

    // operator=, which is copying operator
    flist& operator=(const flist& other) {
        if (this != &other) {
            release();
            copy(other);
        }
        return *this;
    }
    
    flist() = default; //class constructor, set to default
    ~flist() {         //class destructor, which release memory
        release();
    }

//there was line with <template U = T>, but it seemed to be useless so I removed it.
    void add(const T& value) requires (std::integral<T> || std::floating_point<T>) { //function for adding elements to list, concept that force numeric type needed

        // because of concepts, this is unused now
        // if (!std::is_arithmetic<T>::value) { //checking if object type is numeric
        //     std::cerr << "Only numeric types are supported." << std::endl;
        //     return; //empty return becuase error will be passed
        // }

        Link* newElement = new Link{ value };

        if (head == nullptr) {
            head = newElement;
        }

        else {
            Link* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newElement;
        }
    }

    size_t size() const {
        const Link* current = head;
        size_t res = 0;

        while (current != nullptr) {
            res++;
            current = current->next;
        }

        return res;
    }

    T sum() const {
        T res{};
        const Link* current = head;

        while (current != nullptr) {
            res += current->value;
            current = current->next;
        }

        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const flist& list) {
        const Link* current = list.head;
        int index = 0;

        while (current != nullptr) {
            if (current->next == nullptr)
                os << "[" << index << "]: " << current->value << "\n";
            else
                os << "[" << index << "]: " << current->value << " - ";

            current = current->next;
            index++;
        }

        return os;
    }
};

int main() {

    flist<int> f1; //creating int's list - flist class object
    
    //adding a few elements to it, just to check working
    f1.add(5);
    f1.add(6);
    f1.add(4);

    std::cout << "f1: " << f1; //printing f1 content using implemented << operator
    std::cout << "Size: " << f1.size() << "\n"; //checking if size function work
    std::cout << "Sum: " << f1.sum() << "\n"; //checking if sum function work

    // uncomment two lines below to see working of concepts
    // flist<std::string> f2; //trying to create object with string types what shouldn't be possible
    // f2.add("Hello world!"); //and trying to add any string element to the list

    auto f3 = f1; //creating f3, which is copy of f1
    std::cout << "f3: " << f3; //checking if copy of f1 worked
    f3.add(5); //adding any element to f3, copy of f1
    std::cout << "f3: " << f3; //checking if can change values of f3
    std::cout << "f1: " << f1; //checking if f1 is not geting change, when changing f3
    
    return 0;
}