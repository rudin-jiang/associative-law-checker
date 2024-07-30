#pragma once

#include <string>
#include <vector>
#include <stdexcept>

class multitable
{
private:
    std::vector<std::string>        _elems;
    std::vector<std::vector<int>>   _mulTab;

    const int get_index(std::string elem) const;
    const std::string get_elem(int index) const;

public:
    multitable();
    multitable(std::string mulTab);

    std::size_t size() const {
        return _elems.size();
    }

    std::string operator[](std::size_t index) const {
        if (index >= _elems.size()) {
            throw std::runtime_error("index error");
        }
        
        return _elems[index];
    }

    const std::string mult(std::string elem0,
                           std::string elem1) const;
    
    const std::string to_string() const;
};
