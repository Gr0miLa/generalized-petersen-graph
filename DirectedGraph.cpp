#include "DirectedGraph.h"

DirectedGraph::DirectedGraph() :
	numEdges(0), numVertices(0) {}

DirectedGraph::DirectedGraph(size_t _numVertices) :
	numVertices(_numVertices), numEdges(0),
	adjacencyList(_numVertices) {}

DirectedGraph::DirectedGraph(
	std::vector<std::vector<size_t>> otherList) :
	adjacencyList(otherList), numVertices(otherList.size()) {
	for (const auto& adjList : adjacencyList) {
		numEdges += adjList.size();
	}
	numEdges / 2;
}

DirectedGraph::DirectedGraph(const DirectedGraph& otherList) : 
	adjacencyList(otherList.adjacencyList), 
	numEdges(otherList.numEdges), numVertices(otherList.numVertices) {}

void DirectedGraph::addEdge(size_t src, size_t dst) {
	if ((src >= adjacencyList.size()) || (dst >= adjacencyList.size())) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	adjacencyList[src].push_back(dst);
	adjacencyList[dst].push_back(src);
	++numEdges;
}

void DirectedGraph::removeEdge(size_t src, size_t dst) {
	if ((src >= adjacencyList.size()) || (dst >= adjacencyList.size())) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	
	auto itDst = std::find(adjacencyList[src].begin(), 
		adjacencyList[src].end(), dst);
	if (itDst != adjacencyList[src].end()) {
		adjacencyList[src].erase(itDst);
	}
	auto itSrc = std::find(adjacencyList[dst].begin(), 
		adjacencyList[dst].end(), src);
	if (itSrc != adjacencyList[dst].end()) {
		adjacencyList[dst].erase(itSrc);
	}
	--numEdges;
}

void DirectedGraph::addVertex() {
	adjacencyList.push_back(std::vector<size_t>());
	++numVertices;
}

void DirectedGraph::removeVertex(size_t numVertex) {
	if (numVertex >= adjacencyList.size()) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	adjacencyList.erase(adjacencyList.begin() + numVertex);
	for (auto& adjList : adjacencyList) {
		adjList.erase(std::remove_if(adjList.begin(), adjList.end(),
			[&numVertex](int x) { return x == numVertex; }), adjList.end());
	}
	--numVertices;
}
