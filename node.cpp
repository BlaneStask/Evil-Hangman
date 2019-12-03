#include <string>
#include "node.h"

using namespace std;

node::node(string target, node* next){
    mWord = target;

    for(int i = 0; i < mWord.length(); i++){
        mMask += '?';
    }
    mNextNode = next;
}

void node::update_mask(char letter){
    int set_points = get_mask(letter);

    size_t n = mMask.length() - 1;
    while (set_points > 0){
        if (set_points % 2 == 1){
            mMask[n] = mWord[n];
        }
        n--;
        set_points /= 2;
    }
}

int node::get_mask(char letter) const{
    int retval = 0;
    for (int i = 0; i < mWord.length(); i++){
        retval = retval * 2;
        if (mWord[i] == letter){
            retval++;
        }
    }
    return retval;
}
