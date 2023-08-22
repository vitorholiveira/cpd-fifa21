#include "load_data.cpp"

void print_players_table(vector<unsigned int> ids, HashPlayers *hash){
    Player *p;
    for(int i = 0; i < ids.size(); i++){
        p = hash->query(ids[i]);
        if(p != NULL){
            cout << p->id << '\t' << p->name << '\t';
            for(int j = 0; j < p->positions.size() - 1; j++)
                cout << p->positions[j] << ", ";
            cout << p->positions[p->positions.size() - 1] << '\t' << p->rating << '\t' << p->rating_count << endl;
        }
    }
}