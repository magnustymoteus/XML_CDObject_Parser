//
// Created by gruzi on 16/02/2023.
//

#include "CDCatalog.h"
#include "CD.h"
void CDCatalog::print() const {
    std::cout << "------Printing all CDs:------" << std::endl;
    for(CD* currentCD : CDs) {
        currentCD->print();
        std::cout << "---------------------------" << std::endl;
    }
}
CDCatalog::~CDCatalog() {
    for(CD* &currentCD : CDs) {
        delete currentCD;
    }
}