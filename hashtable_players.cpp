#include "hashtable_players.h"

// Hash constructor
HashPlayers::HashPlayers(int n){
    len = n;
    table.resize(n);
}

// Insere o jogador
void HashPlayers::insert(Player p){
    int key = f_hash(p.id);
    Player* current = table[key];
    Player* p_new = new Player;
    *p_new = p;

    if(current != NULL) {
        while(current->tail != NULL && current->id != p.id)
            current = current->tail;

        if(current->id != p.id){
            current->tail = p_new;
        }
    } else {
        table[key] = p_new;
    }

}

// Consulta o id e retorna um ponteiro para o jogador. Se o jogador não foi encontrado retorna NULL;
// MODIFICADA E NÃO TESTADA
Player* HashPlayers::query(unsigned int id){
    int key = f_hash(id);
    Player* current = table[key];
    while(current != NULL){
        if(current->id == id)
            return current;
        current = current->tail;
    }
    return current;
}

// Lê o arquivo csv dado e carrega na hash table
// Se conseguiu abrir o arquivo retorna 1, caso contrário retorna 0.
int HashPlayers::load(string filename){
    Player p;
    string line, element, pos;
    fstream file(filename, ios::in);
    if(!file.is_open()) {
        return 0;
    } 
    getline(file, line);

    while(getline(file, line)) {
        stringstream line_aux(line);

        // ID
        getline(line_aux, element, ',');
        stringstream id(element);
        id >> p.id;

        // NAME
        getline(line_aux, p.name, ',');

        // POSITIONS
        getline(line_aux, element);
        if(element[0] == '"'){ // remove aspas
            element = &element[1]; 
            element[element.length() - 1] = '\0';
        }
        stringstream positions(element);
        while(getline(positions, pos, ',')){
            if(pos[0] == ' ') pos = &pos[1]; // remove espaço
            p.positions.push_back(pos);
        }

        insert(p);
        p.positions.clear();
    }

    file.close();
    return 1;
}

// Adiciona uma nova avaliação para determinado jogador
// NÃO TESTADA
void HashPlayers::add_rating(unsigned int id, float rating){
    Player* p = query(id);
    if(p == NULL)
        return;
    p->rating *= p->rating_count;
    p->rating += rating;
    p->rating_count++;
    p->rating /= p->rating_count;
}