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
	DirectedGraph(size_t _numVertices); // ����������� � ���������� - ���������� ������
	DirectedGraph(std::vector<std::vector<size_t>> otherList); // ����������� � ���������� - ������� (Matrix)
	DirectedGraph(const DirectedGraph& otherList); // ����������� �����������

	void addEdge(size_t src, size_t dst); // ���������� �����
	void removeEdge(size_t src, size_t dst); // �������� �����

	void addVertex(); // ���������� �������
	void removeVertex(size_t numVertex); // �������� �������

	size_t countEdges(const std::vector<std::vector<size_t>>& adjacencyList);

	void setList(std::vector<std::vector<size_t>> otherList); // ������ ������� ���������
	size_t getNumberOfVertices() const; // ������ ���������� ������ �����
	size_t getNumberOfEdges() const; // ������ ���������� ������ �����
	void setNumberOfVertices(size_t number); // ������ ���������� ������ �����

	void drawGraph();

	DirectedGraph& operator=(const DirectedGraph& otherGraph); // �������� ������������
	DirectedGraph& operator=(const std::vector<std::vector<size_t>>& otherList); // �������� ������������

	friend std::ostream& operator<<(std::ostream& os, const DirectedGraph& graph); // ����� �����
	friend std::istream& operator>>(std::istream& is, DirectedGraph& graph); // ���� �����
};

