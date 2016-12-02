// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>

class polygon {
protected:
	int length, width;
public:
	polygon(int x, int y) {
		length = x;
		width = y;
	}
	int area() {
		std::cout << "area" << std::endl;
		return(length * width);
	}

};

class rectangle : public polygon {

public:
	rectangle(int x, int y) :polygon(x, y) {

	}
	bool issquare() {
		if (length == width)
			return true;
		else
			return false;
	}
};

class triangle :public polygon {
public:
	triangle(int x, int y) :polygon(x, y) {}
	int area() {
		std::cout << "triangle" << std::endl;
		return((length * width) / 2);
	}
};
int main() {


std::vector< triangle * > vecttri;

	for (int x = 0; x < 10; x++) {
	triangle *triptr = new triangle(5, x);
	vecttri.push_back(triptr);
	}

	auto biterator = vecttri.begin();//auto 
	while (biterator != vecttri.end()) {
	std::cout << (*biterator)->area() << std::endl;
	biterator++;
	}

	//ok delete
	biterator = vecttri.begin();
	triangle *ptr = NULL;

	while (biterator != vecttri.end()) {
		delete *biterator;
	biterator++;
	}

}

