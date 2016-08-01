#include "Frames.hpp"

std::vector<Frame>* Frames::getFrames(){
	return frames;
}

void Frames::setFrames(std::vector<Frame>* frames){
	this->frames = frames;
}
