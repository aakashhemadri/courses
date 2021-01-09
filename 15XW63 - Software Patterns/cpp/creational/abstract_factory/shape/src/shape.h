#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
#include<config.h>

class Shape {
	public:
		Shape(){
			id_ = total_++;
		}
		virtual void draw() = 0;
	protected:
		int id_;
		static int total_;
};

#endif // SHAPE_H
