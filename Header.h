#pragma once
#include <iostream>

namespace manDotDotDot {
	void func(int var1) {
		int static var2 = 0;
		std::cout << var1 + var2 << " ";
		var2 += var1;
	}
}