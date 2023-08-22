#include "../../data_structures/hashtable_players/hashtable_players.cpp"
#include "../../data_structures/hashtable_tags/hashtable_tags.cpp"
#include "../../data_structures/trie_players/trie_players.cpp"

int load(HashPlayers *hash_players, Trie* trie_players, HashTags *hash_tags);
int load_players(HashPlayers *hash_players, Trie* trie_players, string filename);
int load_users_ratings(HashPlayers *hash_players, string filename);
int load_tags(HashTags *hash_tags, string filename);
