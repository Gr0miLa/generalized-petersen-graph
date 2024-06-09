#pragma once

#include "Graph.h"
#include <string>

class UndirectedGraph : public Graph
{
public:
	UndirectedGraph();
	UndirectedGraph(const Graph& other); // ����������� ����������� Graph
	UndirectedGraph(const UndirectedGraph& other); // ����������� �����������

	void addEdge(size_t src, size_t dst); // ���������� size_t
	void removeEdge(size_t src, size_t dst); // �������� size_t
};
