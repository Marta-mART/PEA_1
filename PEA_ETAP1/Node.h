#ifndef PEA_ETAP1_NODE_H
#define PEA_ETAP1_NODE_H

#include <list>
#include "ResultCostMatrix.h"

using namespace std;

class Node {
private:
    ResultCostMatrix node_rcm;
    vector<int> path;
    int cost;

    Node(vector<int>& path, ResultCostMatrix & rcm, int cost); //konstruktor sluzacy do tworzenia dzeci-wezlow
public:
    Node();
    ~Node() {}

    Node(Graph & gr); //konstruktor wezla-korzenia

    list<Node> getNodeChildren(int vertices_amount);

    int getCost() const;
    vector<int> & getPath();
    int getAmountOfNodesInPath();
    int getLastVertix();
};

bool operator<(const Node& first, const Node& second);

#endif
