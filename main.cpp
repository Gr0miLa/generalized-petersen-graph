#include <iostream>
#include "Matrix.h"
#include "Graph.h"
#include "Algorithms.h"
#include "UndirectedGraph.h"
#include "GeneralizedPetersenGraph.h"
#include "DoubleGeneralizedPetersenGraph.h"

int main()
{
	size_t n = 5;
	size_t chNum = 3;

	std::cout << "Petersen graph with chromatic number " << chNum << " and n = " << n << ":" << std::endl;
	alg::PGraphByChromaticNumber(chNum, n);

	std::cout << std::endl;

	std::cout << "Double Petersen graph with chromatic number " << chNum << " and n = " << n << ":" << std::endl;
	alg::DPGraphByChromaticNumber(chNum, n);

	std::cout << std::endl;

	std::cout << "- - - - - - - - - - - - - - - P(5, 2) - - - - - - - - - - - - - - -" << std::endl << std::endl;
	GeneralizedPetersenGraph petersen(5, 2); // PetersenGraph
	std::cout << petersen.getGraph() << std::endl;
	std::cout << "Vertices: " << petersen.getGraph().getNumberOfVertices() <<
		" Edges: " << petersen.getGraph().getNumberOfEdges() << std::endl << std::endl;
	std::cout << "- - - - - - - - - - - - - P(5, 2) algorithms - - - - - - - - - - - " << std::endl << std::endl;

	std::vector<size_t> petersenColors = alg::colorGraph(petersen.getGraph());
	std::cout << "Colors: ";
	for (auto& elem : petersenColors) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	std::cout << "Chromatic Number: " << alg::chromaticNumber(petersenColors) << std::endl;

	std::vector<size_t> petersenDFS = alg::dfs(petersen.getGraph(), 0);
	std::cout << "DFS: ";
	for (auto& elem : petersenDFS) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	std::vector<size_t> petersenBFS = alg::bfs(petersen.getGraph(), 0);
	std::cout << "BFS: ";
	for (auto& elem : petersenBFS) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;

	//std::cout << "- - - - - - - - - - - - - - - P(9, 3) - - - - - - - - - - - - - - -" << std::endl << std::endl;
	//GeneralizedPetersenGraph petersen2(9, 3); // GeneralizedPetersenGraph
	//std::cout << petersen2.getGraph() << std::endl;
	//std::cout << "Vertices: " << petersen2.getGraph().getNumberOfVertices() << 
	//	" Edges: " << petersen2.getGraph().getNumberOfEdges() << std::endl << std::endl;
	//std::cout << "- - - - - - - - - - - - - P(9, 3) algorithms - - - - - - - - - - - " << std::endl << std::endl;
	//std::vector<size_t> petersenColors2 = alg::colorGraph(petersen2.getGraph());
	//std::cout << "Colors: ";
	//for (auto& elem : petersenColors2) {
	//	std::cout << elem << " ";
	//}
	//std::cout << std::endl;
	//std::cout << "Chromatic Number: " << alg::chromaticNumber(petersenColors2) << std::endl;
	//std::vector<size_t> petersenDFS2 = alg::dfs(petersen2.getGraph(), 0);
	//std::cout << "DFS: ";
	//for (auto& elem : petersenDFS2) {
	//	std::cout << elem << " ";
	//}
	//std::cout << std::endl;
	//std::vector<size_t> petersenBFS2 = alg::bfs(petersen2.getGraph(), 0);
	//std::cout << "BFS: ";
	//for (auto& elem : petersenBFS2) {
	//	std::cout << elem << " ";
	//}
	//std::cout << std::endl;
	//std::cout << std::endl;

	std::cout << "- - - - - - - - - - - - - - - DP(4, 2) - - - - - - - - - - - - - - " << std::endl << std::endl;
	DoubleGeneralizedPetersenGraph doublePetersen(4, 2); // DoubleGeneralizedPetersenGraph
	std::cout << doublePetersen.getGraph() << std::endl;
	std::cout << "Vertices: " << doublePetersen.getGraph().getNumberOfVertices() <<
		" Edges: " << doublePetersen.getGraph().getNumberOfEdges() << std::endl << std::endl;

	std::cout << "- - - - - - - - - - - - - DP(4, 2) algorithms - - - - - - - - - - -" << std::endl << std::endl;

	std::vector<size_t> doublePetersenColors = alg::colorGraph(doublePetersen.getGraph());
	std::cout << "Colors: ";
	for (auto& elem : doublePetersenColors) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	std::cout << "Chromatic Number: " << alg::chromaticNumber(doublePetersenColors) << std::endl;

	std::vector<size_t> doublePetersenDFS = alg::dfs(doublePetersen.getGraph(), 0);
	std::cout << "DFS: ";
	for (auto& elem : doublePetersenDFS) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	std::vector<size_t> doublePetersenBFS = alg::bfs(doublePetersen.getGraph(), 0);
	std::cout << "BFS: ";
	for (auto& elem : doublePetersenBFS) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;

	//std::cout << "- - - - - - - - - - - - - - - DP(10, 9) - - - - - - - - - - - - - -" << std::endl << std::endl;
	//DoubleGeneralizedPetersenGraph doublePetersen2(10, 7); // DoubleGeneralizedPetersenGraph
	//std::cout << doublePetersen2.getGraph() << std::endl;
	//std::cout << "Vertices: " << doublePetersen2.getGraph().getNumberOfVertices() <<
	//	" Edges: " << doublePetersen2.getGraph().getNumberOfEdges() << std::endl << std::endl;

	return 0;
}