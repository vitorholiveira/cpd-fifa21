#include "../interface/interface.cpp"

void query_players(string command, HashPlayers *hash_players, Trie *trie_players);
//void query_users(string command, HashPlayers *hash_players, HashUsers *hash_users)
void query_top_positions(string command, HashPlayers *hash_players, HashTags *hash_tags);
void query_tags(string command, HashPlayers *hash_players, HashTags *hash_tags);
void query_pos_and_tags(string command, HashPlayers *hash_players, HashTags *hash_tags);
void query_sofifaid(string command, HashPlayers *hash_players);
