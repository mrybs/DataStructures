//
// Created by mrybs on 28.07.2023.
//

#ifndef DATASTRUCTURES_DOUBLYLINKEDLIST_H
#define DATASTRUCTURES_DOUBLYLINKEDLIST_H

namespace DS{

    template <class T>
    class DoublyLinkedList{
    protected:
        struct Node{
            T data;
            Node* next;
            Node* prev;
            Node(T data, Node* next, Node* prev){
                this->data = data;
                this->next = next;
                this->prev = prev;
            }
        };
        Node* head;
        Node* current;
        Node* tail;
        unsigned long long length;


    public:
        DoublyLinkedList(){
            head = nullptr;
            current = head;
            tail = head;
            length = 0;
        }
        ~DoublyLinkedList(){
            delete head;
            delete tail;
        }

        T& operator[](unsigned long long index){
            Node* buffer = head;
            for(unsigned long long i = 0; i <= index; i++){
                if(i == index)
                    return buffer->data;
                buffer = buffer->next;
            }
        }
        void push(T el){
            Node* node = new Node(el, nullptr, nullptr);
            if(head == nullptr){
                head = node;
                tail = head;
                return;
            }
            if(head->next == nullptr){
                head->next = node;
                tail = head->next;
                return;
            }
            tail->next = node;
            Node* temp = tail;
            tail = node;
            tail->prev = temp;
            length++;
        }
        void pop(unsigned long long index){
            if(head == nullptr)
                return;
            at(index);
            Node* prev = current->prev;
            Node* next = current->next;
            if(prev != nullptr)
                prev->next = current->next;
            if(next != nullptr)
                next->prev = current->prev;
            length--;
        }
        unsigned long long size(){
            return length;
        }
        unsigned long long bytes(){
            return length*(sizeof(T)+sizeof(Node*))+(sizeof(T)+sizeof(Node*)*2)*3+sizeof(unsigned long long);
        }
        T& at(unsigned long long index){
            if(index<length/2) {
                if(head == nullptr)
                    return current->data;
                if(index == 0){
                    current = head;
                    return current->data;
                }
                unsigned long long i = 1;
                while(i != index){
                    current = current->next;
                    i++;
                }
                return current->data;
            }else{
                if(tail == nullptr)
                    return current->data;
                if(index == length - 1){
                    current = tail;
                    return current->data;
                }
                unsigned long long i = length-2;
                while(i != index){
                    current = current->prev;
                    i--;
                }
            }
        }
        T& search(T el){
            if(head == nullptr)
                return current->data;
            unsigned long long i = 1;
            while(current->data != el){
                current = current->next;
                i++;
            }
            return current->data;
        }

    };
}

#endif//DATASTRUCTURES_DOUBLYLINKEDLIST_H
