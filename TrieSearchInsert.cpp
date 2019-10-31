#include<iostream>
#include<vector>

using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode{
  struct TrieNode *childeren[ALPHABET_SIZE];
  bool isEndOfWord;
};

struct TrieNode* getNode(void){
  struct TrieNode * pNode = new TrieNode;
  pNode->isEndOfWord = false;
  for(int i = 0; i<26; i++){
    pNode->childeren[i] = NULL;
  }
  return pNode;
}

void insert(struct TrieNode *root, string key){
  struct TrieNode* pCrawl = root;
  for(int i = 0; i<key.length(); i++){
    int index = key[i] - 'a';
    if(!pCrawl->childeren[index])
      pCrawl->childeren[index] = getNode();
    pCrawl = pCrawl->childeren[index];
  }
  pCrawl->isEndOfWord = true;
}

bool Search(struct TrieNode* root, string key){
  struct TrieNode* pCrawl = root;
  for(int i = 0; i<key.length(); i++){
    int index = key[i] - 'a';
    if(!pCrawl->childeren[index])
      return false;
    pCrawl = pCrawl->childeren[index];
  }
  return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main(){
  string arr[] = {"the", "a", "there", "answer", "any", "by", "bye", "thier"};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<string> S(arr, arr+n);

  struct TrieNode *root = getNode();

  for(int i = 0; i<n; i++){
    insert(root, S[i]);
  }
  Search(root, "the") ? cout<<"the is present\n" : cout<<"the is absent\n";
  Search(root, "these") ? cout<<"these is present\n" :cout<<"these is absent\n";
  Search(root, "ans") ? cout<< "ans is present\n" : cout<<"ans is absent\n";
  return 0;
}
