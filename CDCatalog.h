//
// Created by gruzi on 16/02/2023.
//

#ifndef PROJECT_SOFTWARE_PRACTICUM1_CDCATALOG_H
#define PROJECT_SOFTWARE_PRACTICUM1_CDCATALOG_H

#include <vector>
#include <iostream>

class CD;

class CDCatalog {
private:
    std::vector<CD*> CDs;
public:
    CDCatalog() = default;
    CDCatalog(const std::vector<CD*> &CDs) : CDs(CDs) {}

    std::vector<CD*> getCDs() const {return CDs;}
    void setCDs(const std::vector<CD*> &newCDs) {CDs = newCDs;}

    void addCD(CD* const newCD) {CDs.push_back(newCD);}
    void print() const;

    ~CDCatalog();
};


#endif //PROJECT_SOFTWARE_PRACTICUM1_CDCATALOG_H
