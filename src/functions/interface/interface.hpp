#include "../load_data/load_data.cpp"

void print_players_table(vector<unsigned int> ids, HashPlayers *hash);
vector<string> read_args(string command);
int ranking_size(string command);
bool is_number(string str);
bool is_position(string position);
bool has_position(vector<string> args);
string format_command(string command);