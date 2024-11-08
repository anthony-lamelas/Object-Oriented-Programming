/*
Rec10
Anthony Lamelas
Instruments, Musicians, and Orchestra
 */

#include <iostream>
#include <vector>
using namespace std;

// Base Instrument class
class Instrument {
    friend ostream& operator<<(ostream& os, const Instrument& instrument);
public:
    virtual void makeSound() const = 0;
    virtual void play() const = 0;
    virtual void display(ostream& os) const = 0; 
};

void Instrument::makeSound() const {
    cout << "To make a sound...";
}

// Brass instruments
class Brass : public Instrument {
public:
    Brass(int m) : mouthpiece_size(m) {}

    void makeSound() const override {
        Instrument::makeSound();
        cout << " blow on a mouthpiece of size " << mouthpiece_size << endl;
    }

protected:
    virtual void play() const = 0;
    int mouthpiece_size;
};

class Trumpet : public Brass {
public:
    Trumpet(int m) : Brass(m) {}

    void play() const override {cout << "Toot";}

    void display(ostream& os) const override {
        os << "Trumpet: " << mouthpiece_size;
    }
};

class Trombone : public Brass {
public:
    Trombone(int m) : Brass(m) {}

    void play() const override {cout << "Blat";}
    void display(ostream& os) const override {
        os << "Trombone: " << mouthpiece_size;
    }
};

// String instruments
class String : public Instrument {
public:
    String(unsigned p) : pitch(p) {}

    void makeSound() const override {
        Instrument::makeSound();
        cout << " bow a string with pitch " << pitch << endl;
    }

protected:
    unsigned pitch;
};


class Violin : public String {

public:
    Violin(unsigned p) : String(p) {}

    void play() const override {cout << "Screech";}
    void display(ostream& os) const override {
        os << "Violin: " << pitch;
    }

};


class Cello : public String {

public:
    Cello(unsigned p) : String(p) {}

    void play() const override {cout << "Squawk";}
    void display(ostream& os) const override {
        os << "Cello: " << pitch;
    }

};

// Percussion instruments
class Percussion : public Instrument {
public:
    void makeSound() const override {
        Instrument::makeSound();
        cout << " hit me!" << endl;
    }
};

class Drum : public Percussion {

    void play() const override {cout << "Boom";}
    void display(ostream& os) const override {
        os << "Drum";
    }

};

class Cymbal : public Percussion {

    void play() const override {cout << "Crash";}
    void display(ostream& os) const override {
        os << "Cymbal";
    }

};

// MILL class to manage instruments
class MILL {
public:
    friend ostream& operator<<(ostream& os, const MILL& rhs);

    void dailyTestPlay() const {
        for (Instrument* instrumentp : instruments) {
            if (instrumentp) {
                instrumentp->makeSound();
            }
        }
    }

    void receiveInstr(Instrument& instrument) {
        instrument.makeSound();
        for (Instrument*& instrumentp : instruments) {
            if (!instrumentp) {
                instrumentp = &instrument;
                return;
            }
        }
        instruments.push_back(&instrument);
    }

    Instrument* loanOut() {
        for (Instrument*& instrumentp : instruments) {
            if (instrumentp) {
                Instrument* curr_instrument = instrumentp;
                instrumentp = nullptr;
                return curr_instrument;
            }
        }
        return nullptr;
    }

private:
    vector<Instrument*> instruments;
};

// Musician class
class Musician {
public:
    Musician(const string name) : instr(nullptr), name(name) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << name << " has no instr\n";
    }

    void play() {
        if (instr) instr->play();
    }

private:
    Instrument* instr;
    string name;
};

class Orch{
    public:

        void addPlayer(Musician& player){
            players.push_back(&player);
        }

        void play() const {
            for (Musician* player : players){
                player->play();
            }
            cout << endl;
        }

    private:
        vector<Musician*> players;
};

ostream& operator<<(ostream& os, const MILL& rhs) {
    os << "The MILL has the following instruments:";

    bool empty = true;

    for (Instrument* instrumentp : rhs.instruments){
        if (instrumentp != nullptr){
           empty = false;
           break;
        }
    }
     if (empty){
            os << " None" << endl;
        }
    os << endl;

    for (Instrument* instrumentp : rhs.instruments) {
        if (instrumentp) {
            os << *instrumentp << endl;
        }
    }
    return os;
}

ostream& operator<<(ostream& os, const Instrument& instrument) {
    instrument.display(os);
    return os;
}

int main() {

    //
    // PART ONE
    //
    cout << "P A R T  O N E\n";

    cout << "Define some instruments ---------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;
  
    cout << "Define the MILL -----------------------------------------------\n";
    MILL mill;
    cout << "The MILL before adding instruments:\n" << mill << "\n\n";

    cout << "Put the instruments into the MILL -----------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    cout << "\nThe MILL after adding some instruments:\n" << mill << "\n\n";
  
    cout << "Daily test ----------------------------------------------------\n"
	 << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    cout << "Define some Musicians------------------------------------------\n";
    Musician harpo("Harpo");
    Musician groucho("Groucho");
  	
    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    groucho.testPlay();	 // Groucho doesn't have an instrument yet.

    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    groucho.testPlay();	
    mill.receiveInstr(*groucho.giveBackInstr());
    harpo.acceptInstr(mill.loanOut());
    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();
    harpo.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "\nThe MILL after giving out some instruments:\n";
    cout << mill << "\n\n";

    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
    mill.receiveInstr(*groucho.giveBackInstr());

    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
    mill.receiveInstr(*harpo.giveBackInstr());
    cout << endl;

    cout << "dailyTestPlay()" << endl;
       mill.dailyTestPlay();
  
    cout << "\nThe MILL at the end of Part One:\n";
    cout << mill << endl;

    //
    // PART TWO
    //
    cout << "\nP A R T  T W O\n";
    
    Musician bob("Bob");
    Musician sue("Sue");
    Musician mary("Mary");
    Musician ralph("Ralph");
    Musician jody("Judy");
    Musician morgan("Morgan");

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    cout << endl << mill << endl;

}


