#ifndef LIST_H
#define LIST_H

#include <string>
#include <cassert>
#include "node.h"

using namespace std;

class list{
public:
        list() { mFirst = NULL; mLength = 0; }

        list(string file);

        ~list();

        bool split(char alpha);

        node* first() { return mFirst; }

        size_t length() { return mLength; }

        string word();

        string mask() {
                assert(mFirst != NULL);
                return mFirst->mask();
        }

        bool is_guessed() {
                assert(mFirst != NULL);
                return mFirst->is_guessed();
        }
private:
        node* mFirst;
        size_t mLength;
};

#endif
