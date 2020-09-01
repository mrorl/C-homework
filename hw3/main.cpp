#include <iostream>
#include "hw3.h"

int main() {

    setlocale(LC_ALL, "ru");

    std::cout << "lst" << std::endl;
    int_list_t lst;

    std::cout << "push_front, push_back, pop_front, pop_back, insert, erase check:" << std::endl;
    lst.push_front(5);
    lst.push_front(3);
    lst.insert(1,4);

    lst.push_front(1);
    lst.insert(1,2);
    lst.push_back(7);
    lst.insert(5,6);
    lst.push_back(8);
    lst.push_front(222);
    lst.push_front(111);
    lst.push_back(888);
    lst.push_back(999);

    lst.erase(1);
    lst.erase(9);

    lst.pop_front();
    lst.pop_back();
    std::cout << lst << std::endl;

    std::cout << "lst[2] = ";
    std::cout << lst[2] << std::endl;
    std::cout << lst[3] << std::endl;
    std::cout << lst[4] << std::endl;
    std::cout << lst[5] << std::endl;
    std::cout << lst[6] << std::endl;

    std::cout << "int &front:" << std::endl;
    std::cout << lst.front() << std::endl;
    std::cout << "int &back:" << std::endl;
    std::cout << lst.back() << std::endl;

    std::cout << "reverse check:" << std::endl;
    lst.reverse();
    std::cout << lst << std::endl;

    std::cout << "merge, copying operator check:" << std::endl;
    int_list_t lst_new(lst);
    int_list_t lst_new2;
    lst_new2.push_back(11);
    lst_new2.push_back(22);
    lst_new2.push_back(33);

    std::cout << "original(lst): ";
    std::cout << lst << std::endl;
    std::cout << "copied(lst_new): ";
    std::cout << lst_new << std::endl;
    std::cout << "lst_new2: ";
    std::cout << lst_new2 << std::endl;

    std::cout << "lst_new.merge(lst_new2);" << std::endl;;
    lst_new.merge(lst_new2);

    std::cout << "lst_new: ";
    std::cout << lst_new << std::endl;
    std::cout << "lst_new2: ";
    std::cout << lst_new2 << std::endl;

    std::cout << "swap check:" << std::endl;
    std::cout << "lst: ";
    std::cout << lst << std::endl;
    std::cout << "lst_new: ";
    std::cout << lst_new << std::endl;
    lst.swap(lst_new);
    std::cout << "lst: ";
    std::cout << lst << std::endl;
    std::cout << "lst_new: ";
    std::cout << lst_new << std::endl;

    std::cout << "int_list_t(size_t count, int value) check:" << std::endl;
    int_list_t val(5,4);
    int_list_t lst1 = val;
    std::cout << "lst1: ";
    std::cout << lst1 << std::endl;
    std::cout << "val1: ";
    std::cout << val << std::endl;

    std::cout << "splice check:" << std::endl;
    //int_list_t lst_spl = lst.splice(0,7);
    //int_list_t lst_spl = lst.splice(4,5);
    int_list_t lst_spl = lst.splice(4,7);
    std::cout << lst_spl << std::endl;
    std::cout << lst << std::endl;

    std::cout << "clear check:" << std::endl;
    lst.clear();
    lst.push_front(666);
    lst.push_front(999);
    std::cout << "lst: ";
    std::cout << lst << std::endl;

    std::cout << "cin check:" << std::endl;
    int_list_t a_cin;
    std::cin >> a_cin;
    std::cout << a_cin << std::endl;

    std::cout << "assignment operator check " << std::endl;
    std::cout << "lst: ";
    std::cout << lst << std::endl;
    std::cout << "a_cin: ";
    std::cout << a_cin << std::endl;
    lst = a_cin;
    std::cout << "lst = a_cin " << std::endl;
    std::cout << "lst: ";
    std::cout << lst << std::endl;
    std::cout << "a_cin: ";
    std::cout << a_cin << std::endl;

    int_list_t test;
    test.merge(lst);
    return 0;
}

