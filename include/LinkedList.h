
#ifndef LAB2_1_1_LINKEDLIST_H
#define LAB2_1_1_LINKEDLIST_H

#include <iostream>


template <typename T>
class Node {

public:

    T data;
    Node* next;

    Node(T& data) {//прочитать документацию о явных и не явных конструкторах

        this->data = data;
        this->next = nullptr;
    };

    ~Node() = default;
};

template <typename T>
class LinkedList {

private:

    Node<T>* head;
    Node<T>* tail;

    int currSize;

public:

    //constructor
    LinkedList() {

        head = nullptr;
        tail = nullptr;
        currSize = 0;
    }


    //back methods
    void pushBack(T& data) {

        auto* newNode = new Node<T>(data);

        if (this->currSize == 0) {

            this->pushFront(data);
        }

        this->tail->next = newNode;

        this->tail = newNode;

        currSize++;
    }

    T popBack() {

        if (this->currSize == 0) {

            return 1;
        }

        if (head->next == nullptr) {

            popFront();

            return 1;
        }

        Node<T>* buffer = this->head;

        for (int i = 0; buffer->next->next != nullptr; ++i) {

            buffer = buffer->next;
        }

        T toReturn = buffer->next->data;


        delete buffer->next;

        buffer->next = nullptr;

        this->tail = buffer;

        this->currSize--;


        return toReturn;
    }


    //front methods
    void pushFront (T& data) {

        auto* newNode = new Node<T>(data);

        newNode->next = this->head;

        this->head = newNode;

        if (this->currSize == 0) {

            this->tail = newNode;
        }

        currSize++;
    }

    T popFront() {

        if (this->currSize == 0) {

            return 1;
        }

        Node<T>* buffer = this->head->next;

        T toReturn = this->head->data;


        delete this->head;

        head = buffer;

        this->currSize--;


        return toReturn;
    }


    //getter
    T get(int pos) {

        if (pos < 0 || pos >= this->currSize) {

            exit(1);
        }

        Node<T>* buffer = this->head;

        for (int i = 0; i < pos; ++i) {

            buffer = buffer->next;
        }

        return buffer->data;
    }


    //other additional
    int size() {

        return this->currSize;
    }

    void print() {

        int listSize = this->currSize;

        for (int i = 0; i < listSize; ++i) {
            T currentObject = this->get(i);

            std::cout << currentObject << std::endl;
        }
    }

    void clear() {

        if (this->currSize == 0) {

            return;
        }

        int listSize = this->currSize;

        for (int i = listSize - 1; i >= 0; --i) {

            Node<T>* buffer = this->head;

            for (int j = 0; j < i; ++j) {

                buffer = buffer->next;
            }

            delete buffer;
        }

        this->head = nullptr;
        this->tail = nullptr;

        this->currSize = 0;
    }

    void insert(int pos, T& data) {

        if ((pos < 0 || pos >= this->currSize) && this->currSize != 0) {

            return;
        }

        if (pos == 0) {

            this->pushFront(data);

            return;
        }

        if (pos == this->currSize - 1) {

            this->pushBack(data);

            return;
        }


        Node<T>* buffer1 = this->head;
        auto* newNode = new Node<T>(data);


        for (int i = 0; i < pos - 1; ++i) {

            buffer1 = buffer1->next;
        }


        newNode->next = buffer1->next;

        buffer1->next = newNode;

        this->currSize++;
    }

    T remove(int pos) {

        if (this->currSize == 0 || pos < 0 || pos >= this->currSize) {

            return 1;
        }

        if (pos == 0) {

            T buff = this->popFront();

            return buff;
        }

        if (pos == this->currSize - 1) {

            T buff = this->popBack();

            return buff;
        }


        Node<T>* left = this->head;
        Node<T>* right;

        for (int i = 0; i < pos - 1; ++i) {

            left = left->next;
        }

        T toReturn = left->next->data;


        right = left->next->next;

        delete left->next;

        left->next = right;

        this->currSize--;


        return toReturn;
    }

    void reverse() {

        int size = this->currSize;

        for(int i = size - 1; i >= 0; i--){

            T a = this->get(i);

            this->pushBack(a);
        }

        for(int i = 0; i < size; i++){

            this->popFront();
        }
    }

    bool isCycled() {

        Node<T>* rabbit = this->head;

        Node<T>* turtle = this->head;


        for (int i = 0; rabbit != nullptr; ++i) {

            rabbit = rabbit->next;

            if (i % 2 == 1) {

                turtle = turtle->next;
            }

            if (rabbit == turtle) {

                return true;
            }
        }


        return false;
    }
};


#endif
