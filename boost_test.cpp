#include <iostream>
#include <memory>
#include <string>
#include <boost/shared_ptr.hpp>
using namespace std;
struct Foo {
    Foo(int n = 0) noexcept : bar(n) {
        std::cout << "Foo: constructor, bar = " << bar << '\n';
    }
    ~Foo() {
        std::cout << "Foo: destructor, bar = " << bar << '\n';
    }
    int getBar() const noexcept { return bar; }
private:
    int bar;
};
int main() {
    boost::shared_ptr<Foo> p1;
    boost::shared_ptr<Foo> p2;
    p1.reset(new Foo(1));
    p2.reset(new Foo(2));
    printf("p1: %d, p2: %d\n", p1->getBar(), p2->getBar());
    p1 = p2;
    printf("p1: %d, p2: %d\n", p1->getBar(), p2->getBar());


    p1.reset(new Foo(1));
    p2.reset(new Foo(2));
    printf("p1: %d, p2: %d\n", p1->getBar(), p2->getBar());
    p1.swap(p2);
    printf("p1: %d, p2: %d\n", p1->getBar(), p2->getBar());

    p1.reset(new Foo(1));
    p2.reset(new Foo(2));
    printf("p1: %d, p2: %d\n", p1->getBar(), p2->getBar());
//    p1.reset(p2);
    printf("p1: %d, p2: %d\n", p1->getBar(), p2->getBar());
    return 0;
}