#include "Frame.hpp"

class Frames{
	std::vector<Frame> *frames;
public:
	Frames(){
		frames = new std::vector<Frame>;
	}
	Frames(std::vector<Frame> *frames){
		this->frames = frames;
	}

	std::vector<Frame>* getFrames();
	void setFrames(std::vector<Frame>* frames);
};
