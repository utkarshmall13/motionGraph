#include "Frame.hpp"

std::vector<float> * Frame::getChannelValues(){
	return channelValues;
}

void Frame::setChannelValues(std::vector<float> * channelValues){
	this->channelValues = channelValues;
}
