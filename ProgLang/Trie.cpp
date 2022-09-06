
template<class ItemType>
Trie<ItemType>::Trie(){
    child[] = nullptr;
    end = false;
}

template<class ItemType>
void Trie<ItemType>::insert(string key, string keyType, int lvl)
{
    if ((key.length() - lvl) != 0)
    {
        int i = key[lvl]-'!';
        if (child[i] == nullptr)
            child[i]] = new Trie<ItemType>();
        child[key[i].insert(key, keyType, lvl++);
        return;
    }
    
    this->keyType = keyType;
    this->end = true;
}