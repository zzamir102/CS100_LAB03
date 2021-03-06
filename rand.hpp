#ifndef __RAND_HPP__
#define __RAND_HPP__
#include "base.hpp"
#include <cstdlib> 
#include <string>
using namespace std;

class Rand : public Base {
	public:
		Rand() : Base() {
			val = rand() % 100; 
		}
		virtual double evaluate() { return val; }
       		virtual string stringify() {
			string str;
			str = to_string(val);
			return str; 
		}
   	 private:
		double val;
};

#endif //__RAND_HPP__


