#include <iostream>

#include "enum_helper.h"

#define TEST_ENUM(n, m) \
    m(n, one, = 1)      \
    m(n, two)           \
    m(n, three)
CREATE_ENUM_CLASS_OSTREAM(MyEnum, TEST_ENUM)

int main()
{
    MyEnum e1 = MyEnum::one;
    MyEnum e2 = MyEnum::two;
    MyEnum e3 = MyEnum::three;
    std::cout << e1 << ':' << static_cast<int>(e1) << '\n'
              << e2 << ':' << static_cast<int>(e2) << '\n'
              << e3 << ':' << static_cast<int>(e3) << '\n';

    return 0;
}
