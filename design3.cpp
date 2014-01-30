// design3.cpp: Implements Alistair's 3rd CoffeeMachine Design
// NOTE: This version doesn't use std::string because of
// a problem with the <sstream> header in today's
// compilers (it doesn't eat the newline).
// Member functions are defined in situ to save space.
// For simplicity, this implementation zeroes-out the
// credit after each drink is dispensed (see returnCoins()).

#include <stdio.h>
#include <string.h>
#include <assert.h>

// We make Selection a class:
// Provides conversions to and from ints and strings.

class Selection
{
public:
enum {BLACK, WHITE, SWEET, BOTH, BOUILLION, NUM_SELECT};
Selection(int c)
{
assert(0 <= c && c < NUM_SELECT);
choice = c;
}
Selection(const char* s)
{
for (int i = 0; i < NUM_SELECT; ++i)
if (strcmp(text[i], s) == 0)
{
choice = i;
return;
}
throw "Selection: bad action";
}
const char* toString() const {return text[choice];}
int priceOf() const {return price[choice];}
operator int() const {return choice;}
private:
int choice;
static int price[NUM_SELECT];
static const char* text[NUM_SELECT];
};

// Static data for Selection class:
int Selection::price[Selection::NUM_SELECT] = {35,35,35,35,25};
const char* Selection::text[Selection::NUM_SELECT] =
{
"black", "white", "sweet", "both", "boullion"
};
// CashBox class:
// Tracks the amount of credit.

class CashBox
{
public:
CashBox() {credit = 0;}
void deposit(int amount)
{
credit += amount;
printf("\tCashBox: Depositing %d cents.",amount);
printf("\tYou now have %d cents credit.\n",credit);
}
void returnCoins()
{
printf("\tCashBox: Returning %d cents\n",credit);
credit = 0;
}
bool haveYou(int amount) const {return credit >= amount;}
void deduct(int amount)
{
credit -= amount;
returnCoins();
}
private:
int credit;
};
// Mixer class:
// Doesn't do much!
class Mixer
{
public:
void make(const Selection& s)
{
printf("\tMixer: Making %s\n", s.toString());
}
};
// Selector class:
// Checks credit; Dispenses product.
class Selector
{
public:
Selector(CashBox* pC, Mixer* pM)
{
pCashBox = pC;
pMixer = pM;
}

void select(const Selection& s)
{
int amount = s.priceOf();
if (pCashBox->haveYou(amount))
{
pMixer->make(s);
pCashBox->deduct(amount);
}
else
puts("\tSelector: Insufficient funds");
}
private:
CashBox* pCashBox;
Mixer* pMixer;
};
// CoffeeMachine class:
// Owns CashBox, Mixer, and Selector.
class CoffeeMachine
{
public:
CoffeeMachine()
{
pCashBox = new CashBox;
pMixer = new Mixer;
pSelector = new Selector(pCashBox, pMixer);
}

bool doOneAction()
{
// Reads commands and executes them.
char line[16];
if (gets(line))
{
char action[7];
sscanf(line, "%s", action);
if (strcmp(action, "insert") == 0)
{
int value;
sscanf(line, "%*s %d", &value);
pCashBox->deposit(value);
}
else if (strcmp(action,"select") == 0)
{
char choice[9];
sscanf(line, "%*s %s", choice);
pSelector->select(choice);
}
else if (strcmp(action,"quit") == 0)
return false;
return true;
}
else
return false;
}





private:
CashBox* pCashBox;
Mixer* pMixer;
Selector* pSelector;
};
// Test program
main()
{
try
{
CoffeeMachine cm;
while (cm.doOneAction())
;
}
catch (const char* s)
{
puts(s);
}
return 0;
}
/* Input:
insert 25
insert 25
select white
insert 50
select boullion
quit
*/

/* Output:
CashBox: Depositing 25 cents. You now have 25 cents credit.
CashBox: Depositing 25 cents. You now have 50 cents credit.
Mixer: Making white
CashBox: Returning 15 cents
CashBox: Depositing 50 cents. You now have 50 cents credit.
Mixer: Making boullion
CashBox: Returning 25 cents
*/
