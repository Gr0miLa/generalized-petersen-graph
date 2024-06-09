#include "UndirectedGraph.h"

//  ŒÕ—“–” “Œ–€

UndirectedGraph::UndirectedGraph() {}

UndirectedGraph::UndirectedGraph(const Graph& other) : Graph(other) {}

UndirectedGraph::UndirectedGraph(const UndirectedGraph& other) {
	adjacencyMatrix = other.adjacencyMatrix;
	numOfEdges = other.numOfEdges;
	numOfVertices = other.numOfVertices;
}

// Ã≈“Œƒ€

void UndirectedGraph::addEdge(size_t src, size_t dst) {
	adjacencyMatrix.setElement(src, dst, true);
	adjacencyMatrix.setElement(dst, src, true);
	++numOfEdges;
}

void UndirectedGraph::removeEdge(size_t src, size_t dst) {
	adjacencyMatrix.setElement(src, dst, false);
	adjacencyMatrix.setElement(dst, src, false);

	--numOfEdges;
}
