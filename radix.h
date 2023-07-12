#ifndef MSD_SORT_H
#define MSD_SORT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

class MSD {
private:
    static const int BITS_PER_BYTE;
    static const int BITS_PER_INT;
    static const int R;
    static const int CUTOFF;

    static int charAt(const std::string& word, int d);
    static void sort(std::vector<std::string>& word, int low, int high, int d, std::vector<std::string>& aux);
    static void insertion(std::vector<std::string>& word, int low, int high, int d); 
    static bool less(const std::string& word1, const std::string& word2, int d) ;


public:
    static std::map<std::string, int> top1000Occurrences(std::map<std::string, int>& ocorrencias) ;
    static std::map<std::string, int> countOccurrences(std::vector<std::string>& vector);
    static void sort(std::vector<std::string>& vector); 

};

void print_vetor(std::vector<std::string>& vetor);

#endif  // MSD_SORT_H