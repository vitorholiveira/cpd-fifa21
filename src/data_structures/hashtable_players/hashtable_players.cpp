#include "hashtable_players.hpp"

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