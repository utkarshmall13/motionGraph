#include "Frames.hpp"

class Edge{
	Frames frames;
public:
	Edge(){
		Frames * framesP = new Frames();
		frames = *framesP;
	}
	Edge(Frames frames){
		this->frames = frames;
	}

	Frames getFrames();
	void setFrames(Frames frames);
};
