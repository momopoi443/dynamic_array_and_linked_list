
#ifndef LAB2_1_1_DYNAMICARR_H
#define LAB2_1_1_DYNAMICARR_H

#define COEFFICIENT 2

#include <iostream>


template <typename T>
class DynamicArr {

private:

    int capacity;

    int currSize;

    T* innerArr;

    void memRealloc(int newCapacity) {

        auto* buffer = new T [newCapacity];

        int buffer1 = currSize;

        if (currSize > newCapacity) {

            buffer1 = newCapacity;
        }

        for (int i = 0; i < buffer1; ++i) {

            buffer[i] = innerArr[i];
        }

        delete [] innerArr;

        innerArr = buffer;

        capacity = newCapacity;
//        this->innerArr = (Robot*) realloc(this->innerArr, newCapacity);
//
//         if (this->innerArr == nullptr) {
//             exit(1);// это нужно чем-то заменить
//         } else {
//             this->capacity = newCapacity;
//         }
    }

    void fullCheck() {

        if (this->currSize == this->capacity) {

            memRealloc(this->capacity * COEFFICIENT);
        }
    }

    void emptyCheck() {

        if ((double) this->currSize / this->capacity < 0.4) {


            memRealloc(this->capacity / COEFFICIENT);
        }
    }

public:

    //constructor/destructor
    DynamicArr(int capacity = 4) {

        this->capacity = capacity;

        this->currSize = 0;

        this->innerArr = new T [capacity];
    }

    ~DynamicArr() {

        delete[] innerArr;
    }


    //back methods
    void pushBack(T data) {

        this->fullCheck();

        this->innerArr[currSize] = data;

        this->currSize++;
    }

    T popBack() {

        if (this->currSize == 0) {

            return 1;
        }

        T toReturn = get(currSize - 1);

        this->currSize--;

        emptyCheck();

        return toReturn;
    }


    //front methods
    void pushFront(T& data) {

        this->fullCheck();

        int size = this->currSize;

        T buffer = this->get(size - 1);

        this->pushBack(buffer);

        for (int i = size - 2; i >= 0; --i) {

            buffer = this->get(i);

            this->set(i + 1, buffer);
        }

        this->innerArr[0] = data;
    }

    T popFront() {

        if (currSize == 0) {

            return 1;
        }

        int size = this->size();

        T toReturn = get(0);

        for (int i = 0; i < size - 1; ++i) {

            T buffer = this->get(i + 1);

            this->set(i, buffer);
        }

        this->currSize--;

        emptyCheck();

        return toReturn;
    }


    //getter setter
    T get(int pos) {

        if (pos >= this->currSize || pos < 0) {

            return 1;
        }

        return this->innerArr[pos];
    }

    void set(int pos, T& data) {

        if (pos >= this->currSize || pos < 0) {

            return;
        }

        this->innerArr[pos] = data;
    }


    //other additional
    int size() {

        return this->currSize;
    }

    void print() {

        int size = this->currSize;

        for (int i = 0; i < size; ++i) {

            T currentObject = this->get(i);

            std::cout << currentObject << std::endl;
        }
    }

    void clear() {

        if (currSize == 0) {

            return;
        }

        delete[] innerArr;

        DynamicArr();
    }

    void insert(int pos, T& data) {

        if ((pos < 0 || pos >= this->currSize) && this->currSize != 0) {

            return;
        }

        this->fullCheck();

        T buffer = this->get(this->currSize - 1);

        this->pushBack(buffer);

        for (int i = this->currSize - 2; i >= pos; --i) {

            buffer = this->get(i);

            this->set(i + 1, buffer);
        }

        this->innerArr[pos] = data;
    }

    T remove(int pos) {

        if (pos >= this->currSize || pos < 0 || this->currSize == 0) {

            return 1;
        }


        T toReturn = get(pos);

        for (int i = pos; i < this->currSize - 1; ++i) {

            T buffer = this->get(i + 1);

            this->set(i, buffer);
        }

        this->currSize--;

        memRealloc(this->capacity - 1);

        return toReturn;
    }
};


#endif
