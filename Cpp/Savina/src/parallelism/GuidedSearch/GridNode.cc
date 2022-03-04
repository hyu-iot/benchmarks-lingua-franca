// Copyright (C) 2020 TU Dresden


#include "GridNode.hh"
#include <cmath>
#include <algorithm>

bool GridNode::setParent(GridNode* node) {
    GridNode* tmp = nullptr;
    return parentInPath.compare_exchange_strong(tmp, node, std::memory_order_relaxed);
}

double GridNode::distanceFrom(const GridNode* node) {
    const long iDiff = i - node->i;
    const long jDiff = j - node->j;
    const long kDiff = k - node->k;
    return sqrt((iDiff * iDiff) + (jDiff * jDiff) + (kDiff * kDiff));
}

bool GridNode::addNeighbor(GridNode* node) {
    if(node == this) {
        return false;
    }
    if(std::find(std::begin(neighbors), std::end(neighbors), node) ==
            std::end(neighbors)) {
        neighbors.push_back(node);
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const GridNode& g) {
    os << "[" << g.i << ", " << g.j << ", " << g.k << "]";
    return os;
}
