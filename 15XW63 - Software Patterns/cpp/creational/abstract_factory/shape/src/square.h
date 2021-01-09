#ifndef SQUARE_H
#define SQUARE_H

class Square : pulic Shape {
	public:
		void draw(){
			std::cout << "Square " << id_ << ": #---#" << std::endl;	
			std::cout << "Square " << id_ << ": |   |" << std::endl;
			std::cout << "Square " << id_ << ": #---#" << std::endl;
		}
};

#endif // SQUARE_H
