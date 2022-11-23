// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful

template<typename valueType, typename cont>
void read_file_to_cont(std::ifstream& f, cont& c) {
    valueType value;
    while(f >> value){
        c.push_back(value);
    }
}

template<typename valueType, typename cont>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    cont container;
    read_file_to_cont<valueType, cont>(fi, container);
    my_selection_sort(container.begin(), container.end());
    if (fo.is_open()) {
        for (auto i = container.begin(); i != container.end(); ++i) {
            fo << *i << std::endl;
        }
    }
}

template<typename valueType>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
    if (fi.is_open()) {
        char container;
        fi >> container;
        fo << container << std::endl;
        switch(container)
        {
            case 'l':
                read_and_sort<valueType, std::list<valueType>>(fi, fo);
                break;
            case 'v':
                read_and_sort<valueType, std::vector<valueType>>(fi, fo);
                break;
            case 'd':
                read_and_sort<valueType, std::deque<valueType>>(fi, fo);
                break;
        }
    }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
    if (fi.is_open()) {
        char type;
        fi >> type;
        fo << type << std::endl;
        switch(type)
        {
            case 'i':
                read_and_sort_decide_container<int>(fi, fo);
                break;
            case 'u':
                read_and_sort_decide_container<unsigned>(fi, fo);
                break;
            case 'f':
                read_and_sort_decide_container<float>(fi, fo);
                break;
            case 'd':
                read_and_sort_decide_container<double>(fi, fo);
                break;
            case 'c':
                read_and_sort_decide_container<char>(fi, fo);
                break;
            case 's':
                read_and_sort_decide_container<std::string>(fi, fo);
                break;
        }
    }
}
