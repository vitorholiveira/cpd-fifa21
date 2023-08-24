#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

typedef struct t {
    string tag;
    vector<unsigned int> ids;
    vector<float> rating;
    t* tail = NULL;
} Tag;

class HashTags {
    int f_hash(string tag){
        int key = 0;
        for(int i = 0; i < tag.length(); i++) key += tag[i];
        return (key*13 % len);
    };
    public:
        unsigned int len;
        vector<Tag*> table;
        // CONSTRUCTOR
        HashTags(int n);
        // METHODS
        void insert(string tag, unsigned int sofifa_id);
        vector<unsigned int> query(string tag);
        vector<unsigned int> intersec(vector<unsigned int> v0, vector<unsigned int> v1);
        vector<unsigned int> intersec_tags(vector<string> tags);
};