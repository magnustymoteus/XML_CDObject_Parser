//
// Created by gruzi on 16/02/2023.
//
#include <iostream>
#include <map>

#include "tinyxml.h"
#include "CD.h"
#include "CDCatalog.h"

int main() {
    // Oefening 1 en 2
    TiXmlDocument doc1;
    std::map<std::string, std::string> CDProperties;
    if(!doc1.LoadFile("eenCD.xml")) {
        std::cerr << doc1.ErrorDesc() << std::endl;
        return 1;
    }
    TiXmlElement* root1 = doc1.FirstChildElement();
    for(TiXmlElement* elem = root1->FirstChildElement(); elem != nullptr; elem = elem->NextSiblingElement()) {
        CDProperties.insert({elem->Value(), elem->GetText()});
    }
    CD cdObject = CD(CDProperties);
    cdObject.print();

    //Oefening 3
    TiXmlDocument doc;
    CDCatalog catalog;
    if(!doc.LoadFile("cdCatalog.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    try {
        TiXmlElement *root2 = doc.FirstChildElement();
        for (TiXmlElement *parentElem = root2->FirstChildElement();
             parentElem != nullptr; parentElem = parentElem->NextSiblingElement()) {
            std::map<std::string, std::string> currentCDProperties;
            for (TiXmlElement *elem = parentElem->FirstChildElement();
                 elem != nullptr; elem = elem->NextSiblingElement()) {
                currentCDProperties.insert({elem->Value(), elem->GetText()});
            }
            CD *currentCDObject = new CD(currentCDProperties);
            catalog.addCD(currentCDObject);
        }
        catalog.print();
    }
    catch(...) {
        std::cout << "Error trying to parse document" << std::endl;
    }
    return 0;
}