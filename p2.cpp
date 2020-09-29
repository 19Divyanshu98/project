
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure for Trie 
struct Trie { 
    bool isEndOfWord; 
    unordered_map<char, Trie*> map; 
    int freq; 
}; 
  
// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
    Trie* node = new Trie; 
    node->isEndOfWord = false; 
    return node; 
} 
  
// Function to insert a word with its meaning 
// in the dictionary built using a Trie 
void insert(Trie*& root, const string& str, 
            int freq  ) 
{ 
  
    // If root is null 
    if (root == NULL) 
        root = getNewTrieNode(); 
  
    Trie* temp = root; 
    for (int i = 0; i < str.length(); i++) { 
        char x = str[i]; 
  
        // Make a new node if there is no path 
        if (temp->map.find(x) == temp->map.end()) 
            temp->map[x] = getNewTrieNode(); 
  
        temp = temp->map[x]; 
    } 
  
    // Mark end of word and store the meaning 
    temp->isEndOfWord = true; 
    temp->freq = freq; 
} 
  
// Function to search a word in the Trie 
// and return its meaning if the word exists 
int getMeaning(Trie* root, const string& word) 
{ 
  
    // If root is null i.e. the dictionary is empty 
    if (root == NULL) 
        return -1; 
  
    Trie* temp = root; 
  
    // Search a word in the Trie 
    for (int i = 0; i < word.length(); i++) { 
        temp = temp->map[word[i]]; 
        if (temp == NULL) 
            return -1; 
    } 
  
    // If it is the end of a valid word stored 
    // before then return its meaning 
    if (temp->isEndOfWord) 
        return temp->freq; 
    return -1; 
} 
  
// Driver code 
int main() 
{ 
    Trie* root = NULL; 
  
    fstream fin;
    string line, word, f;
    string delimiter = ",";
    int freq;
    fin.open("EnglishDictionary.csv",ios::in);
    while (fin) { 
  
        getline(fin, line); 
  
        word = line.substr(0,line.find(delimiter));
        f=line.substr(line.find(delimiter)+1, line.size());
        freq = stoi(f);
        insert(root,word,freq);
    } 
    fin.close(); 

   
    string str = "science"; 

    while(1){
        cout<<"Enter The word to be searched (enter \"q\" to quit)"<<endl; 
        cin>> str;
        if(str != "q")
            cout << getMeaning(root, str)<<endl; 
        else
            break;
        
    }  
    return 0; 
} 