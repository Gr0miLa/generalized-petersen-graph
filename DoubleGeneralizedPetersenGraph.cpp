#include "DoubleGeneralizedPetersenGraph.h"

DoubleGeneralizedPetersenGraph::DoubleGeneralizedPetersenGraph() {}

DoubleGeneralizedPetersenGraph::DoubleGeneralizedPetersenGraph(size_t _n, size_t _k) {
	n = _n;
	k = _k;
	if ((n < 3) || (k < 1) || (k > n - 1)) {
		std::cout << "Invalid argument" << std::endl;
		return;
	}
	graph.setNumberOfVertices(4 * n);
	for (size_t i = 0; i < n; ++i) {
		graph.addEdge(i, ((i + 1) % n));
		graph.addEdge(i, i + n);
		graph.addEdge(i + n, ((i + k) % n) + (2 * n));
		graph.addEdge(i + 2 * n, ((i + k) % n) + n);
		graph.addEdge(i + 2 * n, i + 3 * n);
		graph.addEdge(i + 3 * n, ((i + 1) % n + (3 * n)));
	}
}

UndirectedGraph DoubleGeneralizedPetersenGraph::getGraph() const {
	return graph;
}

std::string DoubleGeneralizedPetersenGraph::getName() const {
	return "DP(" + std::to_string(n) + ", " + std::to_string(k) + ")";
}
