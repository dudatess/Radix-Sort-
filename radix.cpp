#include "radix.h"

void print_vetor(std::vector<std::string>& vetor)
{
    for(auto &string : vetor)
        std::cout << string << std::endl;
}

const int MSD::BITS_PER_BYTE = 8;
const int MSD::BITS_PER_INT = 32;
const int MSD::R = 256;
const int MSD::CUTOFF = 15;

int MSD::charAt(const std::string& word, int d) 
{
    if (d == word.length()) 
        return -1;
    return word[d];
}

void MSD::sort(std::vector<std::string>& word, int low, int high, int d, std::vector<std::string>& aux)
{
    if (high <= low + CUTOFF) {
        insertion(word, low, high, d);
        return;
    }

    std::vector<int> count(R + 2, 0);
    for (int i = low; i <= high; i++) {
        int c = charAt(word[i], d);
        count[c + 2]++;
    }

    for (int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];

    for (int i = low; i <= high; i++) {
        int c = charAt(word[i], d);
        aux[count[c + 1]++] = word[i];
    }

    for (int i = low; i <= high; i++)
        word[i] = aux[i - low];

    for (int r = 0; r < R; r++)
        sort(word, low + count[r], low + count[r + 1] - 1, d + 1, aux);
}

void MSD::insertion(std::vector<std::string>& word, int low, int high, int d) 
{
    for (int i = low; i <= high; i++)
        for (int j = i; j > low && less(word[j], word[j - 1], d); j--)
            std::swap(word[j], word[j - 1]);
}

bool MSD::less(const std::string& word1, const std::string& word2, int d) 
{
    for (int i = d; i < std::min(word1.length(), word2.length()); i++) {
        if (word1[i] < word2[i]) return true;
        if (word1[i] > word2[i]) return false;
    }
    return word1.length() < word2.length();
}

void MSD::sort(std::vector<std::string>& vector) 
{
    int size = vector.size();
    std::vector<std::string> aux(size);
    sort(vector, 0, size - 1, 0, aux);
}

std::map<std::string, int> MSD::countOccurrences(std::vector<std::string>& vector) 
{
    std::map<std::string, int> occurrences;
    for (const std::string& word : vector) {
        occurrences[word]++;
    }
    return occurrences;
}

std::vector<std::pair<std::string, int>> MSD::top1000Occurrences(std::map<std::string, int>& ocorrencias)
{
    std::vector<std::pair<std::string, int>> ocorrenciasVec;

    for (const auto& pair : ocorrencias) {
        ocorrenciasVec.push_back(pair);
    }

    std::sort(ocorrenciasVec.begin(), ocorrenciasVec.end(), [](const auto& a, const auto& b) {
            
        if (a.second != b.second) {

            return a.second > b.second; 
        } 
        else {
            return a.first < b.first; 
        }
    });

    if (ocorrenciasVec.size() > 1000) {
        ocorrenciasVec.resize(1000);
    }

    return ocorrenciasVec;
}