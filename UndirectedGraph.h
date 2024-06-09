#pragma once

#include "Graph.h"
#include <string>

class UndirectedGraph : public Graph
{
public:
	UndirectedGraph();
	UndirectedGraph(const Graph& other); // Конструктор копирования Graph
	UndirectedGraph(const UndirectedGraph& other); // Конструктор копирования

	void addEdge(size_t src, size_t dst); // Добавление size_t
	void removeEdge(size_t src, size_t dst); // Удаление size_t
};
