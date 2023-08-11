#include "hashtable_tags.h"

HashTags::HashTags(int n){
    len = n;
    table.resize(n);
}

int HashTags::load(string filename){
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

void HashTags::insert(string tag, unsigned int sofifa_id){
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
    } else if(sofifa_id != current->ids.back()){
        current->ids.push_back(sofifa_id);
    }
}

vector<unsigned int> HashTags::query(string tag){
    int key = f_hash(tag);
    Tag* current = table[key];
    while(current != NULL){
        if(current->tag == tag)
            return current->ids;
        current = current->tail;
    }
    vector<unsigned int> v;
    return v;
}

vector<unsigned int> HashTags::intersec_tags(vector<string> tags){
    vector<unsigned int> v = query(tags[0]);
    for(int i = 1; i < tags.size(); i++)
        v = intersec(v, query(tags[i]));
    return v;
}

vector<unsigned int> HashTags::intersec(vector<unsigned int> v0, vector<unsigned int> v1){
    vector<unsigned int> v2;
    for(int i = 0; i < v0.size(); i++)
        for(int j = 0; j < v1.size(); j++)
            if(v0[i] == v1[j])
                v2.push_back(v0[i]);
    return v2;
}