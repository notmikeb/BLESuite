//============================================================================
// Name        : boost_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <boost/python.hpp>
using namespace std;
using namespace boost::python;

string greet(){
	return "hello";
}

BOOST_PYTHON_MODULE(hello){
	using namespace boost::python;
	def("greet",greet);
}
