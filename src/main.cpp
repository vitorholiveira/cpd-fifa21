#include "./functions/queries/queries.cpp"
#include <chrono>

int main(int argc, char **argv){
    int len, open, last_char, size;
    string command;
    vector<unsigned int> ids;
    vector<string> args;
    chrono::time_point<chrono::system_clock> begin, end;

    len = 10000;
    HashPlayers hash_players(len);
    HashTags hash_tags(len);
    HashUsers hash_users(len);
    Trie trie_players;

    begin = chrono::system_clock::now();
    open = load(&hash_players, &trie_players, &hash_tags, &hash_users);
    //load_positions(&hash_players, &hash_tags);
    end = chrono::system_clock::now();
    chrono::duration<double> time = end - begin;

    cout << endl << "Tempo de inicializacao: " << time.count() << "s" << endl;
    
    if(!open){
        cout << endl << "Nao foi possivel abrir os arquivos CSV" << endl;
        return 2;
    }

    do{
        cout << endl << "-----------------------------------------------------------------------------------------" << endl << endl;
        getline(cin, command);
        cout << endl;
        command = format_command(command);
        if(command.substr(0,7) == "player ")
            query_players(command, &hash_players, &trie_players);
        else if(command.substr(0,5) == "user ")
            query_users(command, &hash_players, &hash_users);
        else if(command.substr(0,3) == "top")
            query_top_positions(command, &hash_players, &hash_tags);
        else if(command.substr(0,5) == "tags ")
            query_tags(command, &hash_players, &hash_tags);
        else if(command.substr(0,9) == "pos&tags ")
            query_pos_and_tags(command, &hash_players, &hash_tags);
        else if(command.substr(0,9) == "sofifaid ")
            query_sofifaid(command, &hash_players);
        else if(command != "quit")
            cout << "Comando invalido!" << endl;
    }while(command != "quit");

    return 0;
}