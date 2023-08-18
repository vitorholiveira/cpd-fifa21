#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

typedef struct p{
    unsigned int id;
    string name;
    float rating = 0;
    unsigned int rating_count = 0; 
    vector<string> positions;
    p *tail = NULL;
} Player;

class HashPlayers{
    unsigned int len;
    vector<Player*> table;
    int f_hash(unsigned int n){
        return (n % len);
    };
    public:
        // CONSTRUCTOR
        HashPlayers(int n);
        // METHODS
        void insert(Player p);
        void add_rating(unsigned int id, float rating);
        Player* query(unsigned int id);
};
