#include "./load_data.hpp"

int load(HashPlayers *hash_players, Trie* trie_players, HashTags *hash_tags, HashUsers *hash_ratings){
    return (load_tags(hash_tags, "../data/tags.csv") &&
            load_players(hash_players, trie_players, hash_tags, "../data/players.csv") &&
            load_users_ratings(hash_players, hash_ratings, "../data/rating.csv"));
}

int load_players(HashPlayers *hash_players, Trie* trie_players, HashTags *hash_tags, string filename){
    Player p;
    string element;
    fstream file(filename, ios::in);
    
    if(!file.is_open()){
        cout << "Nao foi possivel abrir o arquivo " << filename << endl;
        return 0;
    }

    getline(file, element);
        // SOFIFA ID
    while(getline(file, element, ',')){
        p.id = stoi(element);
        // NAME
        getline(file, p.name, ',');
        // POSITIONS
        getline(file, element);
        if(element[0] != '"'){
            p.positions.push_back(element); // tem só uma posição
            hash_tags->insert(element, p.id); // insere o a posicao como uma tag
        }else{
            element[element.length() - 1] = '\0'; // remove fecha aspas
            stringstream positions(element);
            while(getline(positions, element, ',')){
                element = &element[1]; // remove espaço e aspa abre aspas na primeira exec
                p.positions.push_back(element);
                hash_tags->insert(element, p.id); // insere a posicao como uma tag
            }
        }
        // INSERE DADOS
        hash_players->insert(p);
        trie_players->insert(p.name, p.id);
        p.positions.clear();

    }
    file.close();
    return 1;
}

int load_users_ratings(HashPlayers *hash_players, HashUsers *hash_users, string filename){
    string element;
    int sofifa_id, user_id;
    float rating;
    Rating r;
    fstream file(filename, ios::in);

    if(!file.is_open()){
        cout << "Nao foi possivel abrir o arquivo " << filename << endl;
        return 0;
    }

    getline(file, element);
        // USER ID
    while(getline(file, element, ',')){
        user_id = stoi(element);
        // SOFIFA ID
        getline(file, element, ',');
        sofifa_id = stoi(element);
        // POSITIONS
        getline(file, element);
        rating = stof(element);

        r.p_id = sofifa_id;
        r.rating = rating;

        hash_users->insert(r, user_id);
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
    while(getline(file, element, ',')) {
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