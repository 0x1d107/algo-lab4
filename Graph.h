#pragma once
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <locale>
#include <codecvt>
#include <iostream>
#include <sstream>
#include <algorithm>

/// номера вершин - числа 1..n
// соседи вершины i


class Graph {
	std::vector<std::vector<int>> edges;
	void dfs1(std::fstream &file,int v);
	void dfs2( std::fstream &file,int v);
	void Kosaraju(std::fstream &file);
	std::vector<bool> visited;
	std::vector<int> order;
	std::vector<std::vector<int>> components;
	
public:


	Graph(int n);

	void AddEdge(int a, int b, int w);


	void IllustratePath(std::string s);

};

