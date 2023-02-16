//
// Created by gruzi on 16/02/2023.
//

#ifndef PROJECT_SOFTWARE_PRACTICUM1_CD_H
#define PROJECT_SOFTWARE_PRACTICUM1_CD_H

#include <iostream>
#include <map>

class CD {
private:
    std::string artist, title, country, company;
    int year;
    float price;
    bool canConvertToPrice(const std::string &price) const;
    bool canConvertToYear(const std::string &year) const;
public:
    CD() = default;
    CD(const std::map<std::string, std::string> &properties);
    std::string getArtist() const {return artist;}
    std::string getTitle() const {return title;}
    int getYear() const {return year;}
    float getPrice() const {return price;}
    std::string getCountry() const {return country;}
    std::string getCompany() const {return company;}

    void setArtist(const std::string &newArtist) {artist=newArtist;}
    void setTitle(const std::string &newTitle) {title=newTitle;}
    void setYear(const int &newYear) {year=newYear;}
    void setPrice(const float &newPrice) {price=newPrice;}
    void setCountry(const std::string &newCountry) {country=newCountry;}
    void setCompany(const std::string &newCompany) {company=newCompany;}

    void print() const;
};


#endif //PROJECT_SOFTWARE_PRACTICUM1_CD_H
