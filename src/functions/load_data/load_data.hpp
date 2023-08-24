#include "../../data_structures/hashtable_players/hashtable_players.cpp"
#include "../../data_structures/hashtable_tags/hashtable_tags.cpp"
#include "../../data_structures/hashtable_users/hashtable_users.cpp"
#include "../../data_structures/trie_players/trie_players.cpp"

int load(HashPlayers *hash_players, Trie* trie_players, HashTags *hash_tags, HashUsers *hash_ratings);
int load_players(HashPlayers *hash_players, Trie* trie_players, HashTags *hash_tags, string filename);
int load_users_ratings(HashPlayers *hash_players, HashUsers *hash_users, string filename);
int load_tags(HashTags *hash_tags, string filename);
void load_positions(HashPlayers *hash_players, HashTags *hash_tags);
