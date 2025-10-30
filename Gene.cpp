#include "Gene.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 


//Constructors logic
Gene::Gene() {
    id = "";
    sequence = "";
    propensity = 0.0;
};

Gene::Gene(const std::string &geneId, const std::string &geneSeq){
    this->id = geneId;
    this->sequence = geneSeq;
    propensity = 0.0;
}

//Getters and Setters logic

//For Id values
std::string Gene::getId() const {
    return id;
}

void Gene::setId(const std::string &newId){
    this->id = newId;
}

//For Sequence values
std::string Gene::getSequence() const {
    return sequence;
}

void Gene::setSequence(const std::string &newSequence) {
    this->sequence = newSequence;
}

//For Propensity values
double Gene::getPropensity() const {
    return propensity;
}

void Gene::setPropensity(const double newPropensity){
    this->propensity = newPropensity;
}


//toString Function for formatted output
std::string Gene::toString() const { 
    std::ostringstream oss;
    oss << "Gene ID: " << id
        << "Gene Sequence: " << sequence
        << "Gene Propensity: " << std::fixed << std::setprecision(4) << propensity;
    return oss.str();
}

//Implement relational operators
bool Gene::operator<(const Gene &gene2) const {
    return propensity < gene2.propensity;
}

bool Gene::operator<=(const Gene &gene2) const {
    return propensity <= gene2.propensity;
}

bool Gene::operator>(const Gene &gene2) const {
    return propensity > gene2.propensity;
}

bool Gene::operator>=(const Gene &gene2) const {
    return propensity >= gene2.propensity;
}

bool Gene::operator==(const Gene &gene2) const {
    return propensity == gene2.propensity;
}

bool Gene::operator!=(const Gene &gene2) const {
    return propensity != gene2.propensity;
}

//Implement I/O stream

//Output operator
std::ostream& operator<<(std::ostream &os, Gene &gene){
    os << std::quoted(gene.id) << "," << std::quoted(gene.sequence) << "," << gene.propensity;
    return os;
}

//Input operator
std::istream& operator>>(std::istream &is, Gene &gene){
    char comma;
    is >> std::quoted(gene.id) >> comma >> std::quoted(gene.sequence) >> comma >> gene.propensity;
    return is;
}
