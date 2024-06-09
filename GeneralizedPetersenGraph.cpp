#include "GeneralizedPetersenGraph.h"

GeneralizedPetersenGraph::GeneralizedPetersenGraph() {}

GeneralizedPetersenGraph::GeneralizedPetersenGraph(size_t _n, size_t _k) {
	n = _n;
	k = _k;
	if ((n < (2 * k + 1)) || ((2 * k + 1) < 3)) {
		std::cout << "Invalid argument" << std::endl;
		return;
	}
	graph.setNumberOfVertices(2 * n);
	for (size_t i = 0; i < n; ++i) {
		graph.addEdge(i, ((i + 1) % n));
		graph.addEdge(i, i + n);
		graph.addEdge(i + n, ((i + k) % n) + n);
	}
}

UndirectedGraph GeneralizedPetersenGraph::getGraph() const {
	return graph;
}

std::string GeneralizedPetersenGraph::getName() const {
	return "P(" + std::to_string(n) + ", " + std::to_string(k) + ")";
}
