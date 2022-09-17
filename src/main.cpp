#include <iostream>
#include <ctime>

#include "../include/Robot.h"
#include "../include/LinkedList.h"
#include "../include/DynamicArr.h"

void test() {

    auto* arr = new DynamicArr<Robot>();

    auto* list = new LinkedList<Robot>();

    Robot robotEx = Robot();

    Robot robotEx1 = Robot(1);

    int size1 = 25;

    int size2 = 5;

    int size3 = 10;

    int size4 = 2;

    int size5 = 2;

    clock_t startTime = clock();

    for (int i = 0; i < size1; ++i) {

        list->pushBack(robotEx);
    }

    clock_t endTime = clock();

    double  time = (double(endTime - startTime) / CLOCKS_PER_SEC);

    std::cout << time << " - time of pushing back to list" << std::endl;

    startTime = clock();

    for (int i = 0; i < size1; ++i) {

        arr->pushBack(robotEx);
    }

    endTime = clock();

    time = (double(endTime - startTime) / CLOCKS_PER_SEC);

    std::cout << time << " - time of pushing back to dynamic array" << std::endl;

    std::cout << std::endl;

    clock_t startTime1 = clock();

    for (int i = 0; i < size2; ++i) {

        list->pushFront(robotEx1);
    }

    clock_t endTime1 = clock();

    double  time1 = (double(endTime1 - startTime1) / CLOCKS_PER_SEC);

    std::cout << time1 << " - time of pushing front to list" << std::endl;

    startTime1 = clock();

    for (int i = 0; i < size2; ++i) {

        arr->pushFront(robotEx);
    }

    endTime1 = clock();

    time1 = (double(endTime1 - startTime1) / CLOCKS_PER_SEC);

    std::cout << time1 << " - time of pushing front to dynamic array" << std::endl;

    std::cout << std::endl;

    clock_t startTime2 = clock();

    for (int i = 0; i < size3; ++i) {

        list->get(rand() % size1 + size2);
    }

    clock_t endTime2 = clock();

    double  time2 = (double(endTime2 - startTime2) / CLOCKS_PER_SEC);

    std::cout << time2 << " - time of getting from the list" << std::endl;

    startTime2 = clock();

    for (int i = 0; i < size3; ++i) {

        arr->get(rand() % size1 + size2);
    }

    endTime2 = clock();

    time2 = (double(endTime2 - startTime2) / CLOCKS_PER_SEC);

    std::cout << time2 << " - time of getting from the dynamic array" << std::endl;

    std::cout << std::endl;

    clock_t startTime3 = clock();

    for (int i = 0; i < size4; ++i) {

        list->popFront();
    }

    clock_t endTime3 = clock();

    double  time3 = (double(endTime3 - startTime3) / CLOCKS_PER_SEC);

    std::cout << time3 << " - time of popping from front of the list" << std::endl;

    startTime3 = clock();

    for (int i = 0; i < size4; ++i) {

        arr->popFront();
    }

    endTime3 = clock();

    time3 = (double(endTime3 - startTime3) / CLOCKS_PER_SEC);

    std::cout << time3 << " - time of popping from front of the dynamic array" << std::endl;

    std::cout << std::endl;

    clock_t startTime4 = clock();

    for (int i = 0; i < size5; ++i) {

        list->popBack();
    }

    clock_t endTime4 = clock();

    double  time4 = (double(endTime4 - startTime4) / CLOCKS_PER_SEC);

    std::cout << time4 << " - time of popping from back of the list" << std::endl;

    startTime4 = clock();

    for (int i = 0; i < size5; ++i) {

        arr->popBack();
    }

    endTime4 = clock();

    time4 = (double(endTime4 - startTime4) / CLOCKS_PER_SEC);

    std::cout << time4 << " - time of popping from back of the dynamic array" << std::endl;
}

int main() {

    test();

    return 0;
}



