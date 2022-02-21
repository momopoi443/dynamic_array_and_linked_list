#include <iostream>

#define COEFFICIENT 2

// TO DO

// переписать структуры под темплейты
// проверить все методы на и ошибки

class Robot {
public:
    int amountOfArms;
    bool abilityToSpeak;
    std::string gender;

public:
    Robot(int amountOfArms = 0, bool abilityToSpeak = false, std::string gender = "NONE") {
        this->amountOfArms = amountOfArms;
        this->abilityToSpeak = abilityToSpeak;
        this->gender = gender;
    }
};

class Node {
public:
    Robot data;
    Node* next;

    explicit Node(Robot& data) {//прочитать документацию о явных и не явных конструкторах
        this->data = data;
        this->next = nullptr;
    }

    ~Node() = default;
};

class LinkedList {

private:

    Node* head;

public:

    LinkedList() {
        head = nullptr;
    }

    void pushFront (Robot& data) {

        if (this->head == nullptr) {
            this->pushBack(data);

            return;
        }

        Node* buffer = this->head;

        for (int i = 0; buffer->next != nullptr; ++i) {
            buffer = buffer->next;
        }

        Node* newNode = new Node(data);

        buffer->next = newNode;
        buffer->data = newNode->data;
    }

    void pushBack(Robot& data) {

        Node* newNode = new Node(data);

        newNode->next = this->head;

        this->head = newNode;
    }

    Robot get(int index) {

        if (index < 0 || index >= size()) {
            exit(1);
        }

        if (index == 0) {
            return this->head->data;
        }

        Node* buffer = this->head;

        for (int i = 0; i < index; ++i) {
            buffer = buffer->next;
        }

        return buffer->data;
    }

    void popFront() {

        if (this->head == nullptr) {
            return;
        }

        Node* buffer = this->head;

        for (int i = 0; buffer->next->next != nullptr; ++i) {
            buffer = buffer->next;
        }

        delete buffer->next;
    }

    void popBack() {

        Node* buffer = this->head->next;

        delete this->head;

        head = buffer;
    }

    int size() {

        int listSize = 0;

        if (this->head == nullptr) {
            return listSize;
        }

        Node* buffer = this->head;

        for (int i = 0; buffer != nullptr; ++i) {
            buffer = buffer->next;

            listSize++;
        }

        return listSize;
    }

    void printf() {
        int listSize = size();

        for (int i = 0; i < listSize; ++i) {
            Robot currentRobot = this->get(i);

            std::cout << currentRobot.gender << currentRobot.abilityToSpeak << currentRobot.amountOfArms << std::endl;
        }
    }//написать перегрузку для вывода полей робота

    void clear() {

        if (this->head == nullptr) {
            return;
        }

        int listSize = size();

        for (int i = listSize - 1; i >= 0; --i) {

            Node* buffer = this->head;

            for (int j = 0; j < i; ++j) {
                buffer = buffer->next;
            }

            delete buffer;
        }
    }

    void insert(int pos, Robot& data) {

        Node* buffer1 = this->head;

        for (int i = 0; i < pos; ++i) {
            buffer1 = buffer1->next;
        }

        Node* newNode = new Node(data);

        newNode->next = buffer1;
        buffer1 = newNode;
    }

    void remote(int pos) {

        Node* left = this->head;
        Node* right;

        for (int i = 0; i < pos - 1; ++i) {
            left = left->next;
        }

        right = left->next->next;

        delete left;

        left = right;
    }
};

class DynamicArr {

private:

    int capacity;

    int currSize;

    Robot* innerArr;

    void memRealloc (int newCapacity) {
        this->innerArr = (Robot*) realloc(this->innerArr, newCapacity);

         if (this->innerArr == nullptr) {
             exit(1);// это нужно чем-то заменить
         } else {
             this->capacity = newCapacity;
         }
     }

public:

    DynamicArr(int capacity = 4) {

        this->capacity = capacity;

        this->currSize = 0;

        this->innerArr = new Robot [capacity];
     }

    ~DynamicArr() {

        delete[] innerArr;
    }

    void pushBack(Robot& buff) {

        if (this->currSize == this->capacity) {

            memRealloc(this->capacity * COEFFICIENT);
        }

        this->innerArr[currSize] = buff;

        this->currSize++;
    }

    void popBack() {

         if (this->currSize == 0) {
             return;
         }

         this->currSize--;

         memRealloc(this->capacity - 1);
    }

    void pushFront(Robot& buff) {

        if (this->currSize == this->capacity) {

            memRealloc(this->capacity * COEFFICIENT);
        }

        int size = this->size();

        Robot buffer = this->get(size - 1);

        this->pushBack(buffer);

        for (int i = size - 2; i >= 0; --i) {

            buffer = this->get(i);

            this->set(buffer, i + 1);
        }

        this->innerArr[0] = buff;
    }

    void popFront() {

        if (currSize == 0) {

            return;
        }

        int size = this->size();

        for (int i = 0; i < size - 1; ++i) {

            Robot buffer = this->get(i + 1);

            this->set(buffer, i);
        }

        this->currSize--;

        memRealloc(this->capacity - 1);
    }

    Robot get(int pos) {

        if (pos >= this->currSize || pos < 0) {

            return 1;
        }

        return this->innerArr[pos];
    }

    void set(Robot& buff, int pos) {

        if (pos >= this->currSize || pos < 0) {
            return;
        }

        this->innerArr[pos] = buff;
    }

    int size() {

        return this->currSize;
    }

    void print() {

        int size = this->size();

        for (int i = 0; i < size; ++i) {

            Robot currRobot = this->get(i);

            std::cout << currRobot.amountOfArms << currRobot.abilityToSpeak << currRobot.gender << std::endl;
        }
    }

    void clear() {

        delete[] innerArr;

        this->capacity = 4;

        this->currSize = 0;

        this->innerArr = new Robot [capacity];
    }

    void insert(Robot& buff, int pos) {

        if (pos >= this->currSize || pos < 0) {
            return;
        }

        if (this->currSize == this->capacity) {

            memRealloc(this->capacity * COEFFICIENT);
        }

        int size = this->size();

        Robot buffer = this->get(size - 1);

        this->pushBack(buffer);

        for (int i = size - 2; i >= pos; --i) {

            buffer = this->get(i);

            this->set(buffer, i + 1);
        }

        this->innerArr[pos] = buff;
    }

    void remove(int pos) {

        if (pos >= this->currSize || pos < 0) {

            return;
        }

        if (currSize == 0) {

            return;
        }

        int size = this->size();

        for (int i = pos; i < size - 1; ++i) {

            Robot buffer = this->get(i + 1);

            this->set(buffer, i);
        }

        this->currSize--;

        memRealloc(this->capacity - 1);
    }
};

int main() {



    return 0;
}



