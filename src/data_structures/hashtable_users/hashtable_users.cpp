#include "hashtable_users.hpp"

// Hash constructor
HashUsers::HashUsers(int n){
    len = n;
    table.resize(n);
}

// Insere avaliação
void HashUsers::insert(Rating r, unsigned int user_id){
    int key = f_hash(user_id);
    User* current = table[key];
    User* u_new = new User;
    u_new->u_id = user_id;
    u_new->ratings.push_back(r);
    
    //primeiro usuário da key
    if(current == NULL){
        table[key] = u_new;
        return;
    }

    //  verificacao do primeiro usuario da lista
    if(current->u_id == user_id){
        current->ratings.push_back(r);
        return;
    }

    while(current->tail != NULL){
        current = current->tail;
        if(current->u_id == user_id){
            current->ratings.push_back(r); //  adiciona o rating no vetor do usuário
            return;
        }
    }

    // usuário não está na hash
    current->tail = u_new;
}

// Consulta o id do usuário e retorna um ponteiro para o usuário. Se o usuário não foi encontrado retorna NULL;
User* HashUsers::query(unsigned int user_id){
    int key = f_hash(user_id);
    User* current = table[key];

    // linha da tabela vazia
    if(current == NULL)
        return NULL;

    //  verificacao do primeiro usuario da lista
    if(current->u_id == user_id)
        return current;

    // percorre a lista
    while(current->tail != NULL){
        current = current->tail;
        if(current->u_id == user_id)
            return current;
    }

    // usuário nao encontrado
    return NULL;
}




