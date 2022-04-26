#include <fstream>
#include "Graph.h"
using namespace std;




int main() {
    setlocale(LC_ALL, "russian");

    Graph g(7);
    g.AddEdge(0, 1, 1);
    g.AddEdge(1, 0, 1);
    g.AddEdge(2, 1, 1);
    g.AddEdge(2, 6, 1);
    g.AddEdge(5, 2, 1);
    g.AddEdge(5, 4, 1);
    g.AddEdge(4, 3, 1);
    g.AddEdge(0, 3, 1);
    g.AddEdge(1, 4, 1);
    g.AddEdge(5, 2, 1);
    g.AddEdge(6, 5, 1);

    //g.SaveGraph("../../../vis/commands.js");
//    g.IllustrateDFS("../../../vis/commands.js", 0);
    g.IllustratePath("../vis/commands.js");

    return 0;
}