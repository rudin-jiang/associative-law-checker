#include "multitable.hpp"
#include "nhfstr.hpp"
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <cmath>

const int multitable::get_index(std::string elem) const {
    for (std::size_t i = 0; i < _elems.size(); ++i) {
        if (elem == _elems[i]) {
            return int(i);
        }
    }

    throw std::runtime_error("Element " + elem + " is not found.");
    return -1;
}

const std::string multitable::get_elem(int index) const {
    if (index < 0 || index >= _elems.size()) {
        throw std::runtime_error("Index error.");
    }

    return _elems[index];
}

multitable::multitable() {}

multitable::multitable(std::string mulTab) {

    std::vector<std::string> tab = nhfStr::split_string(mulTab, " ");
    std::size_t dim = std::sqrt(tab.size() + 1) - 1;

    // TODO: check dim

    // allocate space
    _elems = std::vector<std::string>(dim);
    _mulTab = std::vector<std::vector<int>>(dim, std::vector<int>(dim));

    // copy elements
    for (std::size_t i = 0; i < dim; ++i) {
        _elems[i] = tab[i];
    }

    // copy table
    for (std::size_t i = 0; i < dim; ++i) {
        for (std::size_t j = 0; j < dim; ++j) {
            std::size_t pos = (dim + 1) * i + j + 1 + dim;
            if (pos >= tab.size()) {
                throw std::runtime_error("pos error");
            }
            _mulTab[i][j] = get_index(tab[pos]);
        }
    }
}

const std::string
multitable::mult(std::string elem0,
                 std::string elem1) const {
    int index0 = get_index(elem0);
    int index1 = get_index(elem1);
    int result = _mulTab[index0][index1];

    return _elems[result];
}

const std::string multitable::to_string() const {
    std::string tabStr = " ";
    for (std::size_t i = 0; i < _elems.size(); ++i) {
        tabStr += " " + _elems[i];
    }

    tabStr += "\n";

    for (std::size_t i = 0; i < _elems.size(); ++i) {
        tabStr += get_elem(i);
        for (std::size_t j = 0; j < _elems.size(); ++j) {
            tabStr += " " + get_elem(_mulTab[i][j]);
        }
        tabStr += "\n";
    }

    return tabStr;
}