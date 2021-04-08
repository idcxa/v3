#include "iostream"
#include "ruby.h"
#include "rice/Module.hpp"

using namespace Rice;
void fen (const char * str) {
	std::cout << str << std::endl;
}

extern "C"
void Init_db_native () {
	define_module('db')
		.define_module_function('parse', &parse);
}