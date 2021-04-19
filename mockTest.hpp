#ifndef __MOCK_TEST_HPP__
#define __MOCK_TEST_HPP__

#include <string>
#include "base.hpp"

using namespace std;

class SevenEightMultMock: public Base {
    public:
        SevenEightMultMock()  { } 

        virtual double evaluate() { return (7.0*8.0); }
        virtual string stringify() { return "7.000000 * 8.000000"; }
};

#endif
