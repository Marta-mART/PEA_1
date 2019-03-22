//
// Created by sergio on 18.10.18.
//

#ifndef PEA_ETAP1_RESULTINGCOSTMATRIX_H
#define PEA_ETAP1_RESULTINGCOSTMATRIX_H


#include "Graph.h"

class ResultCostMatrix {
private:
    int vertices_amount;
    int **memory;
public:
    ResultCostMatrix();
    ResultCostMatrix(Graph& graph);
    ResultCostMatrix(const ResultCostMatrix & rcm);
    ~ResultCostMatrix();

    ResultCostMatrix & operator=(const ResultCostMatrix& rs);

    int reduceMatrix();
    void removeVertix(int from, int to);

    int getCost(int from, int to);
};


#endif //PEA_ETAP1_RESULTINGCOSTMATRIX_H
