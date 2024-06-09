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
	Graph(size_t numVertices); // ����������� � ���������� - ���������� ������
	Graph(Matrix<bool> matrix); // ����������� � ���������� - ������� (Matrix)
	Graph(const Graph& other); // ����������� �����������

	void addEdge(size_t src, size_t dst); // ���������� �����
	void removeEdge(size_t src, size_t dst); // �������� �����

	void addVertex(); // ���������� �������
	void removeVertex(size_t number); // �������� �������

	Matrix<bool> getMatrix() const; // ������ ������� ���������
	void setMatrix(Matrix<bool> matrix); // ������ ������� ���������
	size_t getNumberOfVertices() const; // ������ ���������� ������ �����
	size_t getNumberOfEdges() const; // ������ ���������� ������ �����
	void setNumberOfVertices(size_t number); // ������ ���������� ������ �����

	std::vector<size_t> getAdjVertices(size_t vertex) const; // ������ �������� ������, ������� � ������

	Graph& operator=(const Graph& other); // �������� ������������
	Graph& operator=(const Matrix<bool>& other); // �������� ������������

	friend std::ostream& operator<<(std::ostream& os, const Graph& graph); // ����� �����
	friend std::istream& operator>>(std::istream& is, Graph& graph); // ���� �����
};
