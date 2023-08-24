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
    Player *p;
    if(ids.size() == 0)
        cout << "Nenhum jogador encontrado!" << endl;
    for(int i = 0; i < ids.size(); i++){
        p = hash->query(ids[i]);
        if(p != NULL){
            cout << p->id << '\t' << p->name << endl;
            for(int j = 0; j < p->positions.size() - 1; j++)
                cout << p->positions[j] << ", ";
            cout << p->positions[p->positions.size() - 1] << endl;
            cout << p->rating << '\t' << p->rating_count << endl << endl;
        }
    }
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

void print_user_ratings(User *u, HashPlayers *hash_players){
    Player *p;
    u->ratings = sort_ratings(u->ratings);
    for(int i = 0; i < 20; i++){
        p = hash_players->query(u->ratings[i].p_id);
        cout << p->id << '\t' << p->name << endl << p->rating << '\t' << p->rating_count << '\t' << u->ratings[i].rating << endl << endl;
    }
}

vector<Rating> sort_ratings(vector<Rating> ratings){
    int i, j;
    Rating key;
    
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