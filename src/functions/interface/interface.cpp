#include "./interface.hpp"

bool is_number(string str){
    for(int i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
            return false;
    return true;
 }

int ranking_size(string command){
    int i = 3;
    while(command[i+1] != ' ' && command[i+1] != '\0') i++;
    i -= 2;
    if(is_number(command.substr(3,i)))
        return stoi(command.substr(3,i));
    return 0;
}

string format_command(string command){
    string formated;
    for(int i = 0; i < command.length(); i++){
        if(isspace(command[i]))
            formated += ' ';
        else
            formated += command[i];
        while(isspace(command[i]) && isspace(command[i+1]))i++;
    }
    return formated;
}

vector<string> read_args(string command){
    int i = 0, j = 0;    
    vector<string> v;
    while(command[i]){
        if(command[i] == '\''){
            i++;
            v.push_back("");
            while(command[i] != '\''){
                if(command[i] == '\0'){
                    v.clear();
                    return v;
                }
                v[j] += command[i];
                i++;
            }
            j++;
        }
        i++;
    }
    return v;
}

bool is_position(string position){
    if (position != "GK"  && position != "RB" && position != "RWB" && position != "CB" && position != "LB" && position != "LWB" &&
        position != "CDM" && position != "CM" && position != "CAM" && position != "RM" && position != "RW" && position != "LM"  &&
        position != "LW"  && position != "RF" && position != "CF"  && position != "LF" && position != "ST"){
            return false;
    }
    return true;
}

bool has_position(vector<string> args){
    for(int i = 0; i < args.size(); i++)
        if(is_position(args[i]))
            return true;
    return false;
}

void print_players_table(vector<unsigned int> ids, HashPlayers *hash){
    print_players_table(ids, hash, ids.size());
}

void print_players_table(vector<unsigned int> ids, HashPlayers *hash, int size){
    Player *p;
    vector<Player> players;
    if(ids.size() == 0){
        cout << "Nenhum jogador encontrado!" << endl;
        return;
    }

    for(int i = 0; i < ids.size(); i++){
        p = hash->query(ids[i]);
        if(p != NULL)
            players.push_back(*p);
    }
    players = sort_players(players);

    cout << "sofifa_id" << '\t' << "rating" << "\t\t" << "count" << '\t' << "name and positions" << endl;

    for(int i = 0; i < size; i++){
        // pritn id, nome, rating e rating count
        cout << players[i].id << "\t\t" << players[i].rating << "\t\t" << players[i].rating_count << '\t' << players[i].name << " | ";
        // print das posicoes
        for(int j = 0; j < players[i].positions.size() - 1; j++)
            cout << players[i].positions[j] << ",";
        cout << players[i].positions[players[i].positions.size() - 1] << endl;

    }
}

void print_user_ratings(User *u, HashPlayers *hash_players){
    Player *p;
    u->ratings = sort_ratings(u->ratings);

    cout << "sofifa_id" << '\t'<< "global_rating" << '\t' << "count" << '\t' << "rating" << '\t' <<  "name" << endl;

    for(int i = 0; i < 20; i++){
        p = hash_players->query(u->ratings[i].p_id);
        cout << p->id << "\t\t"  << p->rating << "\t\t"  << p->rating_count << '\t' << u->ratings[i].rating << '\t' << p->name << endl;
    }
}

vector<Rating> sort_ratings(vector<Rating> ratings){
    int i, j;
    Rating key;
    // insertion sort
    for (i = 1; i < ratings.size(); i++) {
        key = ratings[i];
        j = i - 1;
        while (j >= 0 && ratings[j].rating < key.rating) {
            ratings[j + 1] = ratings[j];
            j = j - 1;
        }
        ratings[j + 1] = key;
    }
    return ratings;
}

vector<Player> sort_players(vector<Player> players){
    int i, j;
    Player key;
    // insertion sort
    for (i = 1; i < players.size(); i++) {
        key = players[i];
        j = i - 1;
        while (j >= 0 && players[j].rating < key.rating) {
            players[j + 1] = players[j];
            j = j - 1;
        }
        players[j + 1] = key;
    }
    return players;
}