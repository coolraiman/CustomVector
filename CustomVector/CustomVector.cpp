// CustomVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
    Vector<char> v;
    //v.alloc(20);
    v.pushBack('5');
    v.pushBack('6');
    v.pushBack('7');
    v.pushBack('8');
    v.pushBack('9');
    
    v.pushFront('4');
    v.pushFront('3');
    v.pushBack('D');
    v.pushFront('2');

    v.insert(3, 'G');

    v.popBack();
    v.popBack();
    v.trim();
    v.insert(2, 'F');

    v.popFront();
    v.popBack();
    v.erase(3);
    v.trim();

    std::cout << "space: " << v.getSpace() << std::endl;
    std::cout << "size: " << v.getSize() << std::endl;

    for (int i = 0; i < v.getSize(); i++)
    {
        std::cout << v.at(i) << std::endl;
    }

    v.clear();
    std::cout << "space: " << v.getSpace() << std::endl;
    std::cout << "size: " << v.getSize() << std::endl;

    v.pushBack('5');
    v.pushBack('6');
    v.pushBack('7');
    v.alloc(10);
    v.insert(2, 'G');
    v.trim();
    v.alloc(4);

    std::cout << "space: " << v.getSpace() << std::endl;
    std::cout << "size: " << v.getSize() << std::endl;
    for (int i = 0; i < v.getSize(); i++)
    {
        std::cout << v.at(i) << std::endl;
    }

}


