#include "Frame.hpp"
#include <iostream>

std::vector<float> * Frame::getChannelValues(){
	return channelValues;
}

void Frame::setChannelValues(std::vector<float> * channelValues){
	this->channelValues = channelValues;
}

void Frame::print(){
	for(int i=0;i<channelValues->size();i++){
		std::cout<<(*channelValues)[i]<<" ";
	}
	std::cout<<std::endl;
}
