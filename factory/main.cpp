#include <memory>
#include <iostream>

#include "factory.h"

using namespace dp;

class ProductA : public IProduct
{
  public:
    ProductA() {}
    virtual ~ProductA() {}
    virtual void Polymorphism() {
	std::cout << "This is a ProductA" << std::endl;
    }
};

class ProductB : public IProduct
{
  public:
    ProductB() {}
    virtual ~ProductB() {}
    virtual void Polymorphism() {
        std::cout << "This is a ProductB" << std::endl;
    }
};

int main(int argc, char **argv)
{
    FactoryImpl<ProductA> factoryA;
    FactoryImpl<ProductB> factoryB;
    IProduct *p = factoryA.Create();
    if (p)
        p->Polymorphism();
    auto sp = factoryB.CreateEx();
    if (sp != nullptr)
        sp->Polymorphism();

    return 0;
}
