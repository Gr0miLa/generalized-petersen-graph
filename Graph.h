#pragma once

#include "Matrix.h"
#include <algorithm>
#include <set>
#include <map>

class Graph
{
protected:
	// Directed graph
	Matrix<bool> adjacencyMatrix;
	size_t numOfVertices;
	size_t numOfEdges;

public:
	Graph(); 
	Graph(size_t numVertices); // Конструктор с параметром - количество вершин
	Graph(Matrix<bool> matrix); // Конструктор с параметром - матрица (Matrix)
	Graph(const Graph& other); // Конструктор копирования

	void addEdge(size_t src, size_t dst); // Добавление ребра
	void removeEdge(size_t src, size_t dst); // Удаление ребра

	void addVertex(); // Добавление вершины
	void removeVertex(size_t number); // Удаление вершины

	Matrix<bool> getMatrix() const; // Геттер матрицы смежности
	void setMatrix(Matrix<bool> matrix); // Сеттер матрицы смежности
	size_t getNumberOfVertices() const; // Геттер количества вершин графа
	size_t getNumberOfEdges() const; // Геттер количества вершин графа
	void setNumberOfVertices(size_t number); // Геттер количества вершин графа

	std::vector<size_t> getAdjVertices(size_t vertex) const; // Геттер ветктора вершин, смежных с данной

	Graph& operator=(const Graph& other); // Оператор присваивания
	Graph& operator=(const Matrix<bool>& other); // Оператор присваивания

	friend std::ostream& operator<<(std::ostream& os, const Graph& graph); // Вывод графа
	friend std::istream& operator>>(std::istream& is, Graph& graph); // Ввод графа
};
