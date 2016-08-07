#include "MotionGraph.hpp"

VertexDescriptor MotionGraph::addVertex(Vertex vertex){
	VertexDescriptor v = add_vertex(graph);
	graph[v] = vertex;
	return v;
}

EdgeDescriptor MotionGraph::addEdges(Edge edge,VertexDescriptor u,VertexDescriptor v){
	EdgeDescriptor e;bool b;
	tie(e,b) = add_edge(u,v,graph);
	graph[e]=edge;
	return e;
}

void MotionGraph::removeVertex(VertexDescriptor v){
	clear_vertex(v,graph);
	remove_vertex(v,graph);
}

void MotionGraph::removeEdge(EdgeDescriptor e){
	remove_edge(e,graph);
}

void MotionGraph::removeEdge(VertexDescriptor u,VertexDescriptor v){
	remove_edge(u,v,graph);
}

void MotionGraph::setRootNode(VertexDescriptor rootNode){
	this->rootNode = rootNode;
}

VertexDescriptor MotionGraph::getRootNode(){
	return rootNode;
}

std::vector<Frame>* MotionGraph::randomTraversal(int depth){
	std::vector<Frame> *v = new std::vector<Frame>() ;
	VertexDescriptor curr = rootNode;
	for(int i=0;i<depth;i++){
		int deg = out_degree(curr,graph);
		if(deg==0){
			delete v;
			return NULL;
		}
		OutEdgeIterator j,end;
		tie(j,end) = out_edges(curr,graph);
		int chosen = rand()%deg;
		j+=chosen;
		EdgeDescriptor e = *j;
		v->insert(v->end(),graph[e].getFrame_seq().getFrames()->begin(),graph[e].getFrame_seq().getFrames()->end());
		VertexDescriptor targetVertex = target(e,graph);
		curr = targetVertex;
	}
	return v;
}
