#include "hashtable_players.cpp"

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