#include <iostream>

class  A
{

public:
    A(/* args */){};
    virtual void p(){std::cout << "A\n";}
};

class  B : public A
{

public:
    B(/* args */){};
};

class  C : public B
{

public:
    C(/* args */){};
    void p() override{std::cout << "C\n";}
};

int main(int argc, char const *argv[])
{
    //A *b = new  C();

    float offset = 0;
    offset += 0.02;
    printf("Circular d f : %f \n", offset);

}
