#include "hashtable_players.cpp"
#include "hashtable_tags.cpp"
#include "trie_players.cpp"

int invalid_input(string input){
    int i = 0;
    while(input[i]){
        if(input[i] < '0' || input[i] > '9')
            return 1;
        i++;
    }
    return 0;
}

// Hash dos users também é parametro
int load(HashPlayers *hash_players, HashTags *hash_tags){
    fstream file_rating("rating.csv", ios::in);
    if(!hash_players->load("players.csv") || !hash_tags->load("tags.csv") || !file_rating.is_open()) {
        cout << "Can't open CSV file." << endl;
        return 0;
    }

    string line, element, tag;
    unsigned int sofifa_id;
    float rating;

    getline(file_rating, line);

    while(getline(file_rating, line)) {
        stringstream line_aux(line);

        // USER ID
        getline(line_aux, element, ',');

        // SOFIFA ID
        getline(line_aux, element, ',');
        sofifa_id = stoi(element);

        // POSITIONS
        getline(line_aux, element);
        rating = stof(element);

        hash_players->add_rating(sofifa_id, rating);
    }

    file_rating.close();
    return 1;
}
