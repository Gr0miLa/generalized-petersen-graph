#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class DirectedGraph
{
protected:
	std::vector<std::vector<size_t>> adjacencyList;
	size_t numVertices;
	size_t numEdges;

private:
	DirectedGraph();
	DirectedGraph(size_t _numVertices); // Конструктор с параметром - количество вершин
	DirectedGraph(std::vector<std::vector<size_t>> otherList); // Конструктор с параметром - матрица (Matrix)
	DirectedGraph(const DirectedGraph& otherList); // Конструктор копирования

	void addEdge(size_t src, size_t dst); // Добавление ребра
	void removeEdge(size_t src, size_t dst); // Удаление ребра

	void addVertex(); // Добавление вершины
	void removeVertex(size_t numVertex); // Удаление вершины

	size_t countEdges(const std::vector<std::vector<size_t>>& adjacencyList);

	void setList(std::vector<std::vector<size_t>> otherList); // Сеттер матрицы смежности
	size_t getNumberOfVertices() const; // Геттер количества вершин графа
	size_t getNumberOfEdges() const; // Геттер количества вершин графа
	void setNumberOfVertices(size_t number); // Геттер количества вершин графа

	void drawGraph();

	DirectedGraph& operator=(const DirectedGraph& otherGraph); // Оператор присваивания
	DirectedGraph& operator=(const std::vector<std::vector<size_t>>& otherList); // Оператор присваивания

	friend std::ostream& operator<<(std::ostream& os, const DirectedGraph& graph); // Вывод графа
	friend std::istream& operator>>(std::istream& is, DirectedGraph& graph); // Ввод графа
};

