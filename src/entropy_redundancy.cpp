#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

double calculate_entropy(const string &text) {
    if (text.empty()) {
        return 0.0;
    }

    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    double entropy = 0.0;
    for (const auto &pair : freq) {
        double p = static_cast<double>(pair.second) / text.size();
        entropy -= p * log2(p);
    }
    return entropy;
}

double calculate_redundancy(const string &text, int alphabet_size = 256) {
    // Nếu chuỗi rỗng, độ dư thừa cũng có thể coi là 0 (hoặc tùy định nghĩa bài toán)
    if (text.empty()) {
        return 0.0; 
    }
    
    // H_max = log2(N)
    double max_entropy = log2(alphabet_size); 
    
    // H(X)
    double current_entropy = calculate_entropy(text); 
    
    // redundancy = log2(N) - H(X)
    return max_entropy - current_entropy;
}

int main() {
    string input;
    cout << "Enter a string of characters: ";
    getline(cin, input);

    double entropy = calculate_entropy(input);
    double redundancy = calculate_redundancy(input);

    cout << "Entropy: " << entropy << '\n';
    cout << "Redundancy: " << redundancy << '\n';
    return 0;
}

