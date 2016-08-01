#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/utility.hpp>
#include <stdlib.h>
#include "Vertex.hpp"
#include "Edge.hpp"
#include <map>

using namespace boost;
typedef adjacency_list<vecS, vecS, bidirectionalS,Vertex,Edge> Graph;
typedef typename graph_traits<Graph>::vertex_descriptor VertexDescriptor;
typedef typename graph_traits<Graph>::edge_descriptor EdgeDescriptor;

class MotionGraph{
	typedef typename graph_traits<Graph>::out_edge_iterator OutEdgeIterator;
	Graph graph;
	VertexDescriptor rootNode;
public:
	MotionGraph(){
		graph = Graph(0);
	}
	VertexDescriptor addVertex(Vertex vertex);
	EdgeDescriptor addEdges(Edge edge,VertexDescriptor u,VertexDescriptor v);
	void removeVertex(VertexDescriptor v);
	void removeEdge(EdgeDescriptor e);
	void removeEdge(VertexDescriptor u,VertexDescriptor v);
	void setRootNode(VertexDescriptor rootNode);
	VertexDescriptor getRootNode();
	std::vector<Frame>* randomTraversal(int depth);
};
