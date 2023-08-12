#include "trie_players.h"

void Trie::insert(string name, unsigned int id){
    Node* current = root;
    Node* aux;
    for(int i = 0; i < name.length(); i++){
        aux = is_child(name[i], current->tail);
        if(aux == NULL){
            aux = new Node;
            aux->c = name[i];
            current->tail.push_back(aux);
        }
        if(i == name.length() - 1) // last char
            aux->ids.push_back(id);
        current = aux;
    }
}

Node* Trie::is_child(char c, vector<Node *> child){
    for(int j = 0; j < child.size(); j++){
        if(c == child[j]->c){
            return child[j];
        }
    }
    return NULL;
}

vector<unsigned int> Trie::query(string prefix){
    Node* current = root;
    Node* aux;
    vector<unsigned int> v;
    vector<unsigned int> v2;
    for(int i = 0; i < prefix.length(); i++){
        current = is_child(prefix[i], current->tail);
        if(current == NULL)
            return v;
    }
    v_query.clear();
    v_query.insert(v_query.end(), current->ids.begin(), current->ids.end());
    query_aux(current->tail);
    return v_query;
}

void Trie::query_aux(vector<Node*> nodes){
    Node* aux;
    for(int i = 0; i < nodes.size(); i++){
        v_query.insert(v_query.end(), nodes[i]->ids.begin(), nodes[i]->ids.end());
        query_aux(nodes[i]->tail);
    }
}

int Trie::load(string filename){
    unsigned int sofifa_id;
    string name;
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
        sofifa_id = stoi(element);

        // NAME
        getline(line_aux, name, ',');

        // POSITIONS -  ignora
        getline(line_aux, element);

        insert(name, sofifa_id);
    }

    file.close();
    return 1;
}