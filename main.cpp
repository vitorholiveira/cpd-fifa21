#include "main.h"
#include <chrono>

int main(int argc, char **argv){
    int len, open;
    chrono::time_point<chrono::system_clock> begin, end;

    if(argc < 2 || invalid_input(argv[1])){
        cout << endl << "=====================Input errado!=====================" << endl;
        cout << "Use: ./main M" << endl;
        cout << "M é o tamanho da hash table." << endl;
        cout << "Ex: ./main 1000" << endl;
        cout << "=======================================================" << endl << endl;
        return 1;
    }
    len = stoi(argv[1]);

    HashPlayers hash_players(len);
    HashTags hash_tags(len);

    begin = chrono::system_clock::now();
    open = load(&hash_players, &hash_tags);
    end = chrono::system_clock::now();
    chrono::duration<double> time = end - begin;

    cout << "Tempo de inicializacao: " << time.count() << "s" << endl;

    if(!open) return 2;

    Player* p = hash_players.query(135507);
    cout << endl << p->name << ' ' << p->id << ' ' << p->rating << ' ' << p->rating_count << endl;

    return 0;
}