#include "../load_data/load_data.cpp"

void print_players_table(vector<unsigned int> ids, HashPlayers *hash);
void print_user_ratings(User *u, HashPlayers *hash_players);
vector<string> read_args(string command);
int ranking_size(string command);
bool is_number(string str);
bool is_position(string position);
bool has_position(vector<string> args);
string format_command(string command);
vector<Rating> sort_ratings(vector<Rating> ratings);