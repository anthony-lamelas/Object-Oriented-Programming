#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Book{
    
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << book.title << " " << book.chapters << " " << book.characters << endl;

        for (size_t i = 0; i< book.chap_vect.size(); ++i){

            os << *book.chap_vect[i] << endl;

        }

        return os;
    }
    public:

        Book(const string& t, int c) : title(t), chapters(c) {
            int count = 0;
            for (char c : title){
                count += 1;
            }
            characters = count + chapters;

            for (size_t i =0; i< chapters; ++i){
                chap_vect[i] = new int;
                *chap_vect[i] = 0;
            }
        }

        ~Book(){
            for(size_t i = 0; i < chap_vect.size();++i){
                delete chap_vect[i];
            }
            chap_vect.clear();
        }
    
        //Copy constructor

        Book(const Book& rhs) : chapters(rhs.chapters), title(rhs.title), 
        characters(rhs.characters) {
            for (size_t i = 0; i < rhs.chap_vect.size(); ++i){
                chap_vect.push_back(new int(*rhs.chap_vect[i]));
            }
        }

        //Assignment op

        const Book& operator=(const Book& rhs){
            if(&rhs != this){
                title = rhs.title;
                characters = rhs.characters;
                chapters = rhs.chapters;

                for(size_t i = 0; i < chap_vect.size(); ++i){
                    delete chap_vect[i];
                }

                chap_vect.clear();

                for (size_t i = 0; i < rhs.chap_vect.size(); ++i){
                    chap_vect[i] = new int(*rhs.chap_vect[i]);
            }
            }

            return *this;
        }
    
    //delete method already exists

    private:
        string title;
        int chapters;
        int characters;
        vector<int*> chap_vect;

};