//
// Created by mrybs on 28.07.2023.
//


#ifndef DATASTRUCTURES_ARRAY_H
#define DATASTRUCTURES_ARRAY_H


namespace DS{

    template <class T>
    class Array{
    protected:
        T* data;
        unsigned long long length;
    public:
        Array(){
           length = 0;
        }
        ~Array(){
            delete data;
        }

        T& operator[](unsigned long long index){
            return data[index];
        }
        void push(T el){
            T* buffer = new T[length+1];
            for(unsigned long long i = 0; i < length; i++)
                buffer[i] = data[i];
            buffer[length] = el;
            delete data;
            data = buffer;
            length++;
        }
        unsigned long long size(){
            return length;
        }
        void pop(unsigned long long index){
            T* buffer = new T[length-1];
            for(unsigned long long i = 0; i < length; i++){
                if(i < index)
                    buffer[i] = data[i];
                else if(i > index)
                    buffer[i-1] = data[i];
            }
            delete data;
            data = buffer;
            length--;
        }
        unsigned long long search(T el){
            for(unsigned long long i = 0; i < length; i++)
                if(el == data[i])
                    return i;
            return -1;
        }
        unsigned long long search(T el, auto isEqual){
            for(unsigned long long i = 0; i < length; i++)
                if(isEqual(el, data[i]))
                    return i;
            return -1;
        }
        unsigned long long bytes(){
            return length*sizeof(T)+sizeof(unsigned long long);
        }
    };
}

#endif//DATASTRUCTURES_ARRAY_H
