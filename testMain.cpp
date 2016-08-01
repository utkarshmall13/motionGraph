#include <iostream>
#include <vector>
#include "MotionGraph.hpp"

using namespace std;
using namespace boost;

int main(){
	MotionGraph motionGraph;
	Vertex v1("mocap 08_01",0);
	Vertex v2("mocap 08_02",40);
	Frames frames;
	vector<Frame> frameVec;
	for(int i=0;i<40;i++){
		vector<float> *v = new vector<float>();
		v->push_back(i);
		Frame frame(v);
		frameVec.push_back(frame);
	}
	frames.setFrames(&frameVec);
	Edge e12(frames);
	Edge e21(frames);
	VertexDescriptor vd1 = motionGraph.addVertex(v1);
	VertexDescriptor vd2 = motionGraph.addVertex(v2);
	EdgeDescriptor ed12 = motionGraph.addEdges(e12,vd1,vd2);
	EdgeDescriptor ed21 = motionGraph.addEdges(e21,vd2,vd1);
	vector<Frame> * v = motionGraph.randomTraversal(3);
	for(int i=0;i<v->size();i++){
		cout<<(*((*v)[i].getChannelValues()))[0]<<" ";
	}
	cout<<endl;
}
