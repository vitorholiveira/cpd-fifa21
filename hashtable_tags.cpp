#include "hashtable_tags.h"

Hash_tags::Hash_tags(int n){
    len = n;
    table.resize(n);
}


int Hash_tags::load(string filename){
    unsigned int sofifa_id;
    string line, element, tag;
    fstream file(filename, ios::in);
    if(!file.is_open()) {
        return 0;
    } 
    getline(file, line);

    while(getline(file, line)) {
        stringstream line_aux(line);

        // USER ID - ignorar
        getline(line_aux, element, ',');

        // SOFIFA ID
        getline(line_aux, element, ',');
        sofifa_id = stoi(element);

        // TAG
        getline(line_aux, tag, '\n');

        // INSERT TAG
        insert(tag, sofifa_id);
    }

    file.close();
    return 1;
}

void Hash_tags::insert(string tag, unsigned int sofifa_id){
    int key = f_hash(tag);
    Tag* current = table[key];

    if(current == NULL) {
        Tag* t_new = new Tag;
        t_new->ids.push_back(sofifa_id);
        t_new->tag = tag;
        table[key] = t_new;
        return;
    }

    while(current->tail != NULL && current->tag != tag)
        current = current->tail;

    if(current->tag != tag){
        Tag* t_new = new Tag;
        t_new->ids.push_back(sofifa_id);
        t_new->tag = tag;
        current->tail = t_new;
    } else {
        current->ids.push_back(sofifa_id);
    }
}

Tag* Hash_tags::query(string tag){
    int key = f_hash(tag);
    Tag* current = table[key];
    while(current != NULL){
        if(current->tag == tag)
            return current;
        current = current->tail;
    }
    return current;
}