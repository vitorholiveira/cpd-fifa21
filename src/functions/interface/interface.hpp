#include "../load_data/load_data.cpp"

string format_command(string command);
vector<string> read_args(string command);
int ranking_size(string command);
bool is_number(string str);
bool is_position(string position);
bool has_position(vector<string> args);
vector<Rating> sort_ratings(vector<Rating> ratings);
vector<Player> sort_players(vector<Player> players);
void print_players_table(vector<unsigned int> ids, HashPlayers *hash, int size);
void print_players_table(vector<unsigned int> ids, HashPlayers *hash);
void print_user_ratings(User *u, HashPlayers *hash_players);