//
// Created by gruzi on 16/02/2023.
//

#include "CD.h"

void CD::print() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Artist: " << artist << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Country: " << country << std::endl;
    std::cout << "Company: " << company << std::endl;
}
CD::CD(const std::map<std::string, std::string> &properties) {
    for(std::pair<std::string, std::string> currentProperty : properties) {
        std::string key = currentProperty.first;
        std::string value = currentProperty.second;
        if(key == "TITLE") setTitle(value);
        else if(key == "ARTIST") setArtist(value);
        else if(key == "YEAR") {
            if(canConvertToYear(value)) setYear(std::stoi(value));
            else std::cout << "Error: cannot convert " << value << " to an integer" << std::endl;
        }
        else if(key == "PRICE") {
            if(canConvertToPrice(value)) setPrice(std::stof(value));
            else std::cout << "Error: cannot convert " << value << " to a float" << std::endl;
        }
        else if(key == "COUNTRY") setCountry(value);
        else if(key == "COMPANY") setCompany(value);
    }
}

bool CD::canConvertToPrice(const std::string &price) const {
    int amountOfDots = 0;
    for(char currentChar : price) {
        if(currentChar == '.') amountOfDots++;
        else if(!(currentChar >= '0' && currentChar <= '9')) return false;
    }
    return amountOfDots == 1;
}
bool CD::canConvertToYear(const std::string &year) const {
    for(char currentChar : year) {
        if(!(currentChar >= '0' && currentChar <= '9')) return false;
    }
    return true;
}