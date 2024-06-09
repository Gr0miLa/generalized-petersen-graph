#pragma once

#include "UndirectedGraph.h"

class GeneralizedPetersenGraph
{
private:
	UndirectedGraph graph;
	size_t n;
	size_t k;

public:
	GeneralizedPetersenGraph();
	GeneralizedPetersenGraph(size_t n, size_t k);

	UndirectedGraph getGraph() const;
	std::string getName() const;
};
