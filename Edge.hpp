#include "Frame_seq.hpp"

class Edge{
	Frame_seq frame_seq;
public:
	Edge(){
		frame_seq = *(new Frame_seq());
	}
	Edge(Frame_seq frame_seq){
		this->frame_seq = frame_seq;
	}

	Frame_seq getFrame_seq();
	void setFrame_seq(Frame_seq frame_seq);
};
