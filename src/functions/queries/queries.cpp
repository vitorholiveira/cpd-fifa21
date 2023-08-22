#include "queries.hpp"

void query_players(string command, HashPlayers *hash_players, Trie *trie_players){
    vector<unsigned int> ids = trie_players->query(command.substr(7,command.length() - 1));
    print_players_table(ids, hash_players);
}

/*
void query_users(string command, HashPlayers *hash_players, HashUsers *hash_users){
    if(!is_number(command.substr(4,command.length() - 1))){
        cout << "ID do usuário não é um número" << endl;
        return;
    }
}
*/
void query_top_positions(string command, HashPlayers *hash_players, HashTags *hash_tags){
    int size = ranking_size(command);
    
    if(size == 0){
        cout << "O tamanho do ranking esta incorreto!" << endl;
        return;
    }
    vector<string> args = read_args(command);
    if(args.size() != 1 || !is_position(args[0])){
        cout << "Posicao invalida!" << endl;
        return;
    }
    vector<unsigned int> ids = hash_tags->intersec_tags(args);
    print_players_table(ids, hash_players);
}

void query_tags(string command, HashPlayers *hash_players, HashTags *hash_tags){
    vector<string> args = read_args(command);
    if(args.size() == 0){
        cout << "Tags invalidas!" << endl;
        return;
    }else if(has_position(args)){
        cout << "Uma posicao nao eh uma tag!" << endl;
        return;
    }
    vector<unsigned int> ids = hash_tags->intersec_tags(args);
    print_players_table(ids, hash_players);
}

void query_pos_and_tags(string command, HashPlayers *hash_players, HashTags *hash_tags){
    vector<string> args = read_args(command);
    if(args.size() == 0){
        cout << "Argumentos Invalidos!" << endl;
        return;
    }
    vector<unsigned int> ids = hash_tags->intersec_tags(args);
    print_players_table(ids, hash_players);

}

void query_sofifaid(string command, HashPlayers *hash_players){
    string id_str = command.substr(9,command.length() - 1);
    if(!is_number(command.substr(9,command.length() - 1))){
        cout << "ID do jogador não é um número" << endl;
        return;
    }
    vector<unsigned int> ids;
    ids.push_back(stoi(id_str));
    print_players_table(ids, hash_players);
}