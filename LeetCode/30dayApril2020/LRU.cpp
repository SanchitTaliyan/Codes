#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>

using namespace std;

class LRUCache {
public:
    
    int maxSize;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>> :: iterator> ma;
    
    LRUCache(int capacity) {
        maxSize = capacity;
        cache.clear();
        ma.clear();
    }
    
    int get(int x) {
        if(ma.find(x) == ma.end()) return -1;
    
        auto it = ma[x];
        int y = (*it).second;
        cache.erase(it);
        cache.push_front({x, y});
        ma[x] = cache.begin();
        return y;
    }
    
    void put(int x, int y) {
        if(ma.find(x) == ma.end()) {
            if(cache.size() == maxSize) {
                int Lx = cache.back().first;
                ma.erase(Lx);
                cache.pop_back();
                cache.push_front({x,y});
                ma[x] = cache.begin();
            }
            else{
                cache.push_front({x, y});
                ma[x] = cache.begin();
            }
    }
    else {
        auto it = ma[x];
        cache.erase(it);
        cache.push_front({x, y});
        ma[x] = cache.begin();
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */