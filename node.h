#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class node{
public:
    node(string target, node* next);

    void update_mask(char letter);

    void set_next(node* next)
    { mNextNode = next; }
    
    string word() const {return mWord; }
    string mask() const {return mMask; }
    node* next() const
    { return mNextNode; }
    
    int get_mask(char letter) const;

    bool is_guessed() const { return mWord == mMask; }

private:
    string mWord;
    string mMask;
    node* mNextNode;
};

#endif
