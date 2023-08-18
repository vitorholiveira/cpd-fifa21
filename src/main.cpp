#include "./functions/load_data.cpp"
#include <chrono>

int main(int argc, char **argv){
    int len, open;
    chrono::time_point<chrono::system_clock> begin, end;

    len = 10000;
    HashPlayers hash_players(len);
    HashTags hash_tags(len);
    Trie trie_players;

    begin = chrono::system_clock::now();
    open = load(&hash_players, &trie_players, &hash_tags);
    end = chrono::system_clock::now();
    chrono::duration<double> time = end - begin;

    cout << "Tempo de inicializacao: " << time.count() << "s" << endl;

    if(!open){
        cout << "Nao foi possivel abrir os arquivos CSV" << endl;
        return 2;
    }

    Player* p = hash_players.query(200458);
    cout << endl << p->name << ' ' << p->id << ' ' << p->rating << ' ' << p->rating_count << ' ';
    for(int i = 0; i < p->positions.size() - 1; i++)
        cout << p->positions[i] << ',';
    cout <<  p->positions[p->positions.size() - 1] << endl;

    return 0;
}