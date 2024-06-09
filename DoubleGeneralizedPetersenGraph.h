#pragma once

#include "UndirectedGraph.h"

class DoubleGeneralizedPetersenGraph
{
private:
	UndirectedGraph graph;
	size_t n;
	size_t k;

public:
	DoubleGeneralizedPetersenGraph();
	DoubleGeneralizedPetersenGraph(size_t n, size_t k);

	UndirectedGraph getGraph() const;
	std::string getName() const;
};
