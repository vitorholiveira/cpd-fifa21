#include "hashtable_players.cpp"
#include "hashtable_tags.cpp"
#include "trie_players.cpp"

int invalid_input(string input);

int main(int argc, char **argv){
    int len;

    if(argc < 2 || invalid_input(argv[1])){
        cout << endl << "=====================Input errado!=====================" << endl;
        cout << "Use: ./main M" << endl;
        cout << "M é o tamanho da hash table." << endl;
        cout << "Ex: ./main 1000" << endl;
        cout << "=======================================================" << endl << endl;
        return 1;
    }
    len = stoi(argv[1]);

    Hash hash_fifa(len);
    
    if(!hash_fifa.load("players.csv")) {
        cout << "Can't open CSV file." << endl;
        return 2;
    }

    HashTags hash_tags(len);

    if(!hash_tags.load("tags.csv")) {
        cout << "Can't open CSV file." << endl;
        return 2;
    }

    vector<unsigned int> v;
    v = hash_tags.query("Chinese Super League");

    /*
    int j = 0;
    cout << "Chinese Super League" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
        j++;
    }
    cout << j << ' ' << v.size();
    
    vector<unsigned int> v2;
    Trie trie;
    trie.load("players.csv");
    v2 = trie.query("Fer");
    Player p;
    for(int i = 0; i < v2.size(); i++)
        cout << v2[i] << endl;
    */
    Trie trie;
    trie.load("players.csv");
    v = trie.query("Ney");

    Player* p;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
        p = hash_fifa.query(v[i]);
        cout << p->name << endl;
    }

    
    return 0;
}

int invalid_input(string input){
    int i = 0;
    while(input[i]){
        if(input[i] < '0' || input[i] > '9')
            return 1;
        i++;
    }
    return 0;
}