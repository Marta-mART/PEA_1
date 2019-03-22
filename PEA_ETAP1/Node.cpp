#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
#include "Node.h"

Node::Node() {
    path.push_back(0);
    cost = -1;
}

Node::Node(Graph & gr){
    path.push_back(0);
    node_rcm = ResultCostMatrix(gr);
    cost = node_rcm.reduceMatrix();
}

Node::Node(vector<int> &path, ResultCostMatrix &rcm, int cost) {
    this->path = path;
    this->node_rcm = rcm;
    this->cost = cost;
}

int Node::getCost() const {
    return cost;
}

vector<int> & Node::getPath() {
    return path;
}

int Node::getAmountOfNodesInPath() {
    return path.size();
}

bool operator<(const Node& first, const Node& second) {
    return first.getCost() > second.getCost();
}

list<Node> Node::getNodeChildren(int verticesAmount) {
    list<Node> result;
    int from = getLastVertix();
    int child_cost;
    for(int to = 1; to < verticesAmount; to++){
        if(find(path.begin(), path.end(), to) == path.end()) {
            vector<int> child_path = path;
            child_path.push_back(to);

            ResultCostMatrix child_rcm = node_rcm;
            child_rcm.removeVertix(from, to);
            int reduction_cost = child_rcm.reduceMatrix();

            child_cost = cost + reduction_cost + node_rcm.getCost(from, to);

            Node node(child_path, child_rcm, child_cost);
            result.push_back(node);
        }
    }
    return result;
}

int Node::getLastVertix() {
    vector<int>::iterator it = path.end();
    int result = *(--it);
    return result;
}