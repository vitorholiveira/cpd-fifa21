#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

typedef struct r{
    unsigned int p_id;
    float rating;
} Rating;

typedef struct u{
    unsigned int u_id;
    vector<Rating> ratings;
    u *tail = NULL;
} User;

class HashUsers{
    int f_hash(unsigned int n){
        return (n % len);
    };
    public:
        unsigned int len;
        vector<User*> table;
        // CONSTRUCTOR
        HashUsers(int n);
        // METHODS
        void insert(Rating r, unsigned int user_id);
        User* query(unsigned int user_id);
};