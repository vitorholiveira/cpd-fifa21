#include "./functions/interface.cpp"
#include <chrono>

int main(int argc, char **argv){
    int len, open, query;
    string command;
    vector<unsigned int> ids;
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

    do{
        getline(cin, command);
        if(command.substr(0,6) == "player"){
            ids = trie_players.query(command.substr(6,command.length()-1));
            print_players_table(ids, &hash_players);
        } else if(command.substr(0,4) == "user")
            ;
        else if(command.substr(0,3) == "top")
            ;
        else if(command.substr(0,4) == "tags")
            ;
        else if(command != "quit")
            cout << "Comando invalido!" << endl;
    }while(command != "quit");

    return 0;
}