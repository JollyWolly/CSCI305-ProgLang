


class Trie
{
    private:
        Trie *child[94];
        bool end;
        string keyType;

    public:
        Trie();
        void insert(string key, string keyType, int lvl);


}