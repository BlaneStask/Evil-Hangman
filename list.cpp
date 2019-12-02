#include <fstream>
#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>
#include "list.h"

using namespace std;

list::list(string file){
    ifstream inputFile;
    inputFile.open(file);

    size_t count;
    inputFile >> count;

    mFirst = NULL;
    for(int i = 0; i < count; i++){
        string word;
        inputFile >> word;
        node* new_node = new node(word, mFirst);
        mFirst = new_node;
        mLength++;
    }
}

list::~list(){
    node* p = mFirst;
    while (p != NULL) {
        node* q = p->next();
        delete p;
        p = q;
    }
}

string list::word(){
    // Note: the next line makes the game behave randomly
    srand(time(NULL));
        
    assert(mFirst != NULL);
    int x = rand() % length();
    node* p = mFirst;
    for (int i = 0; i < x; i++){
        p = p->next();
    }
    return p->word();
}


bool list::split(char guess){
    list* lists[64];
    
    // instantiates 64 list objects and store pointers to
    // them in the array
    for (int i = 0; i < 64; i++){
        lists[i] = new list();
    }

    // moves the node so that it is in the array at lists[ndx] where
    // ndx is the value returned by the call to get_mask(guess) on the node
    // Note: this list will be empty at the end of this loop
    while (mFirst != NULL) {
        node *q = mFirst;
        mFirst = mFirst->next();

        q->update_mask(guess);
        int index = q->get_mask(guess);
        q->set_next(lists[index]->first());
        lists[index]->mFirst = q;
        lists[index]->mLength++;
    }
    
    // Finds the longest list in the array lists, stored the index of this in the
    // variable best
    int best = 0;
    for (int i = 1; i < 64; i++){
        if (lists[i]->length() > lists[best]->length()){
            best = i;
        }
    }
    
    // Frees the memory used by all lists except for lists[best]
    for (int i = 0; i < 64; i++){
        if (i != best){
            delete lists[i];
            lists[i] = NULL;
        }
    }

    // Sets the first node in this list to be equal to the first node in lists[best]
    // and the length of this list to be the length of lists[best]
    mFirst = lists[best]->first();
    mLength = lists[best]->length();

    // returns true iff guess is in the string returned by mask()
    return (mFirst->mask().find(guess) != string::npos);
}
