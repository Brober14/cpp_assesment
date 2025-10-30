#ifndef GENE_H
#define GENE_H

#include <string>
#include <iostream> 

class Gene {
    private:
        std::string id;
        std::string sequence;
        double propensity;

    public:

        //Default constructor
        Gene();

        //Ordinary constructor
        Gene(const std::string &geneId, const std::string &geneSequence);

        //Getter/Setter for ID
        std::string getId() const;
        void setId(const std::string &geneId);

        //Getter/Setter for Sequence
        std::string getSequence() const;
        void setSequence(const std::string &geneSeq);

        //Getter/Setter for Propensity
        double getPropensity() const;
        void setPropensity(double propensity);


        //ToString Method for returning a formatted string representation of an object
        std::string toString() const;

        //Override the relational operators
        bool operator<(const Gene &gene2) const;
        bool operator<=(const Gene &gene2) const;
        bool operator>(const Gene &gene2) const;
        bool operator>=(const Gene &gene2) const;
        bool operator==(const Gene &gene2) const;
        bool operator!=(const Gene &gene2) const;

        //Override the I/O Stream operators (friend functions)
        friend std::ostream& operator<<(std::ostream &os, Gene &gene); 
        friend std::istream& operator>>(std::istream &is, Gene &gene);
};

#endif