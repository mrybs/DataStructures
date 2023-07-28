//
// Created by mrybs on 28.07.2023.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

namespace DS{

    template <class T>
    class LinkedList{
    protected:
        struct Node{
            T data;
            Node* next;
            Node(T data, Node* next){
                this->data = data;
                this->next = next;
            }
        };
        Node* head;
        Node* current;
        Node* tail;
        unsigned long long length;


    public:
        LinkedList(){
            head = nullptr;
            current = head;
            tail = head;
            length = 0;
        }
        ~LinkedList(){
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
            Node* node = new Node(el, nullptr);
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
            tail = node;
            length++;
        }
        void pop(unsigned long long index){
            if(head == nullptr)
                return;
            at(index);
            current = current->next;
            length--;
        }
        unsigned long long size(){
            return length;
        }
        unsigned long long bytes(){
            return length*(sizeof(T)+sizeof(Node*))+(sizeof(T)+sizeof(Node*)*2)*3+sizeof(unsigned long long);
        }
        T& at(unsigned long long index){
            if(head == nullptr)
                return current->data;
            if(index == 0) {
                current = head;
                return current->data;
            }
            else if(index == length-1){
                current = tail;
                return current->data;
            }
            unsigned long long i = 1;
            while(i != index){
                current = current->next;
                i++;
            }
            return current->data;
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

#endif//DATASTRUCTURES_LINKEDLIST_H
