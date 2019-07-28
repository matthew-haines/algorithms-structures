#include <iostream>

template <class type>
class LinkedList {
    private:
        struct Element {
            type data;
            Element *next;
        };

        Element* getElement(Element *base, int index) {
            int i = 0;
            Element *pointer = base;
            while (i < index) {
                pointer = pointer->next;
                i++;
            }
            return pointer;
        }

    public:
        int length = 0;
        Element *base;

        void append(type data) {
            Element *element = new Element;
            element->data = data;
            if (length == 0) {
                base = element;
                base->next = nullptr;
            }
            else {
                getElement(base, length-1)->next = element;
            }
            length++;
            return;
        }

        void insert(int index, type data) {
            if (index == length) {
                append(data);
                return;
            }
            Element *newElem = new Element;
            Element *previous;
            if (index == 0) {
                previous = base;
                base = newElem;
            }
            else {
                Element *front = getElement(base, index-1);
                previous = front->next;
                front->next = newElem;
            }
            newElem->next = previous;
            newElem->data = data;
            length++;
            return;
        }

        void prepend(type data) {
            insert(0, data);
        }
        
        type getValue(int index) {
            return getElement(base, index)->data;
        }

        void print() {
            Element *pointer = base;
            std::cout << '[';
            while (true) {
                std::cout << pointer->data;
                pointer = pointer->next;
                if (pointer == nullptr) {
                    std::cout << ']' << std::endl;
                    break;
                }
                std::cout << ", ";
            }
            return;
        }

        void set(int index, type data) {
            Element *element = getElement(base, index);
            element->data = data;
        }

        type pop(int index) {
            Element *popped;
            if (index == 0) {
                popped = base;
                base = base->next;
            }
            else {
                Element *front = getElement(base, index-1);
                popped = front->next;
                front->next = popped->next;
            }
            type data = popped->data;
            free(popped);
            return data;
        }

        void reverse() {
            Element *current;
            Element *next;
            Element *nextnext;
            current = base;
            next = current->next;
            current->next = nullptr;
            while (next->next != nullptr) {
                nextnext = next->next;
                next->next = current;
                current = next;
                next = nextnext;
            }
            next->next = current;
            base = next;
        }
};

int main() {
    LinkedList<int> list;
    list.append(5);
    list.append(8);
    list.append(9);
    list.print();
    list.reverse();
    list.print();
}