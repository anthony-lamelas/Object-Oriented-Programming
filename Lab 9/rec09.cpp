#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned n)
	: numberOfPages(n)
    {}
    //virtual void displayNumPages() const { cout << numberOfPages; }
    virtual void displayNumPages() const = 0;
private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned n)
	: PrintedMaterial(n)
    {}
    void displayNumPages() const override { 
            cout << "Magazine Pages: "; 
            PrintedMaterial::displayNumPages();
            cout << endl;
        }
    
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned n)
	: PrintedMaterial(n)
    {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned n, unsigned numIndxPgs )
	: Book(n),
	  numOfIndexPages(numIndxPgs)
    {}
    void displayNumPages() const override { 
            cout << "TextBook Pages: "; 
            PrintedMaterial::displayNumPages();
            cout << "Index: " << numOfIndexPages << endl;
        }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned n)
	: Book(n)
    {}

    void displayNumPages() const override { 
            cout << "Novel Pages: "; 
            PrintedMaterial::displayNumPages();
        }

private:
};


void displayNumberOfPages(const PrintedMaterial& pm){
    pm.displayNumPages();
}

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    PrintedMaterial* pmP;
    pmP = &text;
    pmP->displayNumPages();
    cout << "\n";

    text.displayNumPages();
    cout << "\n";
    novel.displayNumPages();
    cout << "\n";
    mag.displayNumPages();
    cout << "\n";

    vector<PrintedMaterial*> materials;
    materials.push_back(&text);
    materials.push_back(&novel);
    materials.push_back(&mag);

    for (PrintedMaterial* material : materials){
        material->displayNumPages();
        cout << endl;
    }
}
