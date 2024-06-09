#pragma once

#include "Graph.h"
#include "GeneralizedPetersenGraph.h"
#include "DoubleGeneralizedPetersenGraph.h"
#include <algorithm>
#include <set>
#include <stack>
#include <queue>

namespace alg {
    std::vector<size_t> colorGraph(const Graph& graph) {
        size_t V = graph.getNumberOfVertices();
        std::vector<int> listVertex;
        std::vector<int> colors;
        std::map<int, int> colorMap;

        for (size_t i = 0; i < V; ++i) {
            std::vector<size_t> adj = graph.getAdjVertices(i);
            listVertex.push_back(adj.size());
            colors.push_back(i);
            colorMap[i] = -1;
        }

        std::sort(listVertex.begin(), listVertex.end(), std::greater<int>());

        colorMap[0] = 0;

        for (auto color : colors) {
            for (int i = 0; i < V; ++i) {
                if (colorMap[i] == -1) {
                    bool skip = false;
                    for (auto vertex : graph.getAdjVertices(i)) {
                        if (colorMap[vertex] == color) {
                            skip = true;
                            break;
                        }
                    }
                    if (!skip)
                        colorMap[i] = color;
                }
            }
        }

        std::vector<size_t> result;
        for (size_t i = 0; i < V; ++i) {
            result.push_back(colorMap[i]);
        }

        return result;
    }

    size_t chromaticNumber(std::vector<size_t> colors) {
        std::sort(colors.begin(), colors.end());

        size_t count = 1;

        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] != colors[i - 1]) {
                ++count;
            }
        }
        return count;
    }

    std::vector<size_t> dfs(Graph graph, size_t startVertex) {
        std::vector<size_t> result;
        std::vector<bool> visited(graph.getNumberOfVertices(), false);
        std::stack<size_t> stack;

        stack.push(startVertex);

        while (!stack.empty()) {
            size_t vertex = stack.top();
            stack.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                result.push_back(vertex);

                for (size_t adjVertex : graph.getAdjVertices(vertex)) {
                    if (!visited[adjVertex]) {
                        stack.push(adjVertex);
                    }
                }
            }
        }

        return result;
    }

    std::vector<size_t> bfs(Graph graph, size_t startVertex) {
        std::vector<size_t> result;
        std::vector<bool> visited(graph.getNumberOfVertices(), false);
        std::queue<size_t> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            size_t vertex = queue.front();
            queue.pop();
            result.push_back(vertex);

            for (size_t adjVertex : graph.getAdjVertices(vertex)) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }

        return result;
    }

    void PGraphByChromaticNumber(size_t chNum, size_t numVert) {
        bool count = false;
        for (int k = 1; k <= (numVert - 1) / 2; ++k) {
            GeneralizedPetersenGraph petersenGraph(numVert, k);

            auto coloring = colorGraph(petersenGraph.getGraph());
            auto chromNum = chromaticNumber(coloring);
            // std::cout << "k - " << k << " chNum - " << chromNum << std::endl;

            if (chromNum == chNum) {
                std::cout << petersenGraph.getName() << std::endl;
                count = true;
            }
        }
        if (!count) {
            std::cout << "Nothing" << std::endl;
        }
    }

    void DPGraphByChromaticNumber(size_t chNum, size_t numVert) {
        bool count = false;
        if (numVert < 3) {
            std::cout << "Invalid argument" << std::endl;
            return;
        }
        for (int k = 1; k <= numVert - 1; ++k) {
            DoubleGeneralizedPetersenGraph doublePetersenGraph(numVert, k);

            auto coloring = colorGraph(doublePetersenGraph.getGraph());
            auto chromNum = chromaticNumber(coloring);
            // std::cout << "k - " << k << " chNum - " << chromNum << std::endl;

            if (chromNum == chNum) {
                std::cout << doublePetersenGraph.getName() << std::endl;
                count = true;
            }
        }
        if (!count) {
            std::cout << "Nothing" << std::endl;
        }
    }
}  // namespace alg
