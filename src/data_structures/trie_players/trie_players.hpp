#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>
#include <algorithm>

using namespace std;

typedef struct n{
    char c;
    vector<unsigned int> ids;
    vector<n*> tail;
} Node;

class Trie{
    Node* root = new Node;
    public:
        void insert(string name, unsigned int id);
        Node* is_child(char c, vector<Node*> nodes);
        vector<unsigned int> query(string prefix);
        vector<unsigned int> query_aux(vector<Node*> nodes, vector<unsigned int> v);
};