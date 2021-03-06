//
// FastRunTest.cpp
// Note: When every RunTest finished, it should be pushed into Cakes(Backups).

#include <iostream>
#include <iomanip>

#include "FastRunTest.h"

struct BaseInt
{
    int bint;
};

struct INT : public BaseInt
{
    INT(int in)
    { 
        std::cout << "Begin INT.\n";
        bint = in;
    }

    ~INT()
    {
        std::cout << "End INT.\n";
    }

    static inline INT Get() 
    {
        return INT(10);
    }
};

void func(const BaseInt* in)
{
    std::cout << in->bint << std::endl;
}

int main()
{
    std::cout << std::setfill('-') << std::setiosflags(std::ios::right) << std::setw(20) << "FastRunTest";
    std::cout << std::setfill('-') << std::setiosflags(std::ios::left) << std::setw(16) << '-' << std::endl;
    std::cout << std::setfill('-') << std::setiosflags(std::ios::right) << std::setw(20) << TestName;
    std::cout << std::setfill('-') << std::setiosflags(std::ios::left) << std::setw(16) << '-' << std::endl;

    {
        Test* test1 = Test::Get();
        Test* test2 = Test::Get();

        std::thread th1(access, 1);
        std::thread th2(access, 2);

        th1.join();
        th2.join();

        // When Exit.
        ResourcePool::Get()->Free();

        B b1;
        B b2 = b1;
        b2.x = 3;
        B b3;
        b3 = b2;
        b2.x = 4;
        std::cout << b3.x << std::endl;

        // L-Value Ref.
        func(&INT(10));
    }
}
