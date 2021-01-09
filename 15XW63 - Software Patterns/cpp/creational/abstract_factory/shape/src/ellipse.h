#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse : public Shape {
	public:
		void draw() {
			std::cout << "Ellipse "<< id_ << ":  /--\\" << std::endl;
			std::cout << "Ellipse "<< id_ << ": (----)" << std::endl;
			std::cout << "Ellipse "<< id_ << ":  \\--/" << std::endl;
		}
};

#endif // ELLIPSE_H
