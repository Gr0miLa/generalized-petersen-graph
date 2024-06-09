#include "Graph.h"

//  ŒÕ—“–” “Œ–€

Graph::Graph() : 
	numOfVertices(0), numOfEdges(0) {}

Graph::Graph(size_t numVertices) :
	adjacencyMatrix(numVertices, numVertices, false), 
	numOfVertices(numVertices), numOfEdges(0) {}

Graph::Graph(Matrix<bool> matrix) {
	if (matrix.getColumnCount() != matrix.getRowCount()) {
		std::cout << "Invalid argument" << std::endl;
		return;
	}
	adjacencyMatrix = matrix;
	numOfVertices = matrix.getRowCount();
	numOfEdges = 0;
	for (size_t i = 0; i < matrix.getRowCount(); ++i)
		for (size_t j = i; j < matrix.getColumnCount(); ++j)
			if (matrix.getElement(i, j)) ++numOfEdges;
}

Graph::Graph(const Graph& other) :
	adjacencyMatrix(other.adjacencyMatrix), 
	numOfVertices(other.numOfVertices), 
	numOfEdges(other.numOfEdges) {}

// Ã≈“Œƒ€

void Graph::addEdge(size_t src, size_t dst) {
	if ((src >= adjacencyMatrix.getRowCount()) ||
		(dst >= adjacencyMatrix.getRowCount())) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	adjacencyMatrix.setElement(src, dst, true);
	++numOfEdges;
}

void Graph::removeEdge(size_t src, size_t dst) {
	if ((src >= adjacencyMatrix.getRowCount()) ||
		(dst >= adjacencyMatrix.getRowCount())) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	adjacencyMatrix.setElement(src, dst, false);
	--numOfEdges;
}

void Graph::addVertex() {
	adjacencyMatrix.addRow(false);
	adjacencyMatrix.addColumn(false);
	++numOfVertices;
}

void Graph::removeVertex(size_t number) {
	if (number >= adjacencyMatrix.getRowCount()) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	adjacencyMatrix.removeRow(number);
	adjacencyMatrix.removeColumn(number);
	--numOfVertices;
}

Matrix<bool> Graph::getMatrix() const {
	return adjacencyMatrix;
}

void Graph::setMatrix(Matrix<bool> matrix) {
	if (matrix.getColumnCount() != matrix.getRowCount()) {
		std::cout << "Invalid argument" << std::endl;
		return;
	}
	adjacencyMatrix = matrix;
	numOfVertices = matrix.getRowCount();
	for (size_t i = 0; i < matrix.getRowCount(); ++i)
		for (size_t j = i; j < matrix.getColumnCount(); ++j)
			if (matrix.getElement(i, j)) ++numOfEdges;
}

size_t Graph::getNumberOfVertices() const {
	return numOfVertices;
}

size_t Graph::getNumberOfEdges() const {
	return numOfEdges;
}

void Graph::setNumberOfVertices(size_t number) {
	for (size_t i = 0; i < number; ++i) {
		addVertex();
	}
}

std::vector<size_t> Graph::getAdjVertices(size_t vertex) const {
	std::vector<size_t> result;
	for (size_t i = 0; i < adjacencyMatrix.getRowCount(); ++i) {
		if (adjacencyMatrix.getRow(vertex)[i]) {
			result.push_back(i);
			// std::cout << i;
		}
	}

	return result;
}

// œ≈–≈√–”« ¿ Œœ≈–¿“Œ–Œ¬

Graph& Graph::operator=(const Graph& other) {
	if (this != &other) {
		adjacencyMatrix = other.adjacencyMatrix;
		numOfVertices = other.numOfVertices;
		numOfEdges = other.numOfEdges;
	}
	return *this;
}

Graph& Graph::operator=(const Matrix<bool>& other) {
	if ((&adjacencyMatrix != &other)) {
		if (other.getColumnCount() != other.getRowCount()) {
			std::cout << "Invalid argument" << std::endl;
			return *this;
		}
		adjacencyMatrix = other;
		numOfVertices = other.getRowCount();
		for (size_t i = 0; i < other.getRowCount(); ++i)
			for (size_t j = i; j < other.getColumnCount(); ++j)
				if (other.getElement(i, j)) ++numOfEdges;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
	std::cout << graph.adjacencyMatrix;
	return os;
}

std::istream& operator>>(std::istream& is, Graph& graph) {
	std::cin >> graph.adjacencyMatrix;
	return is;
}