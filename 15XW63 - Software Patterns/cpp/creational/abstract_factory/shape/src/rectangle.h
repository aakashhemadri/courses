#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<iostream>
#include<config.h>

class Rectangle : public Shape {
	public:
		void draw() {
			std::cout << "Rectangle " << id_ << ": #----#" << std::endl;
			std::cout << "Rectangle " << id_ << ": |    |" << std::endl;
			std::cout << "Rectangle " << id_ << ": #----#" << std::endl;
		}
};

#endif // RECTANGLE_H
