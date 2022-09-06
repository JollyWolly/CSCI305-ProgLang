
Trie::Trie(){
    child[] = nullptr;
    end = false;
    keyType = "";
}

void Trie::insert(string key, string keyType, int lvl)
{
    if ((key.length() - lvl) != 0)
    {
        int i = key[lvl]-'!';
        if (child[i] == nullptr)
            child[i]] = new Trie();
        child[key[i].insert(key, keyType, lvl++);
        return;
    }
    
    this->keyType = keyType;
    this->end = true;
}