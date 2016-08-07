#include "Frame_seq.hpp"

std::vector<Frame>* Frame_seq::getFrames(){
	return frames;
}

void Frame_seq::setFrames(std::vector<Frame>* frames){
	this->frames = frames;
}
