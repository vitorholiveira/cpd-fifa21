#include "hashtable_players.cpp"
#include "hashtable_tags.cpp"
#include "trie_players.cpp"

int load_players(HashPlayers *hash_players, Trie* trie_players, string filename);
int load_users_ratings(HashPlayers *hash_players, string filename);
int load_tags(HashTags *hash_tags, string filename);

int load(HashPlayers *hash_players, Trie* trie_players, HashTags *hash_tags){
    return (load_tags(hash_tags, "tags.csv") &&
            load_players(hash_players, trie_players, "players.csv") &&
            load_users_ratings(hash_players, "rating.csv"));
}

int load_players(HashPlayers *hash_players, Trie* trie_players, string filename){
    fstream file("players.csv", ios::in);
    if(!file.is_open()){
        cout << "Nao foi possivel abrir o arquivo " << filename << endl;
        return 0;
    }

    Player p;
    string element;

    getline(file, element);
          // SOFIFA ID
    while(getline(file, element, ',')){
        p.id = stoi(element);
        // NAME
        getline(file, p.name, ',');
        // POSITIONS
        getline(file, element);
        if(element[0] == '"'){ // remove aspas
            element = &element[1]; 
            element[element.length() - 1] = '\0';
        }
        stringstream positions(element);
        while(getline(positions, element, ',')){
            if(element[0] == ' ') element = &element[1]; // remove espaço
            p.positions.push_back(element);
        }
        // INSERE DADOS
        hash_players->insert(p);
        trie_players->insert(p.name, p.id);
        p.positions.clear();
    }
    file.close();
    return 1;
}

int load_users_ratings(HashPlayers *hash_players, string filename){
    fstream file("rating.csv", ios::in);
    if(!file.is_open()){
        cout << "Nao foi possivel abrir o arquivo " << filename << endl;
        return 0;
    }

    string element;
    int sofifa_id, user_id;
    float rating;

    getline(file, element);
          // USER ID
    while(getline(file, element, ',')){
        // SOFIFA ID
        getline(file, element, ',');
        sofifa_id = stoi(element);
        // POSITIONS
        getline(file, element);
        rating = stof(element);

        hash_players->add_rating(sofifa_id, rating);
    }
    file.close();
    return 1;
}

int load_tags(HashTags *hash_tags, string filename){
    unsigned int sofifa_id;
    string element, tag;
    fstream file(filename, ios::in);
    if(!file.is_open()){
        cout << "Nao foi possivel abrir o arquivo " << filename << endl;
        return 0;
    }
    getline(file, element);
          // USER ID - ignorar
    while(getline(file, element)) {
        // SOFIFA ID
        getline(file, element, ',');
        sofifa_id = stoi(element);
        // TAG
        getline(file, tag);
        // INSERT TAG
        hash_tags->insert(tag, sofifa_id);
    }

    file.close();
    return 1;
}
