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
    t* tail = NULL;
} Tag;

class Hash_tags {
    unsigned int len;
    vector<Tag*> table;
    int f_hash(string tag){
        int key = 0;
        for(int i = 0; i < tag.length(); i++) key += tag[i];
        return (key % len);
    };
    public:
        // CONSTRUCTOR
        Hash_tags(int n);
        // METHODS
        int load(string filename);
        void insert(string tag, unsigned int sofifa_id);
        Tag* query(string tag);
};