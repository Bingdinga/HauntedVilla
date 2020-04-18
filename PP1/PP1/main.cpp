/*
HauntedVillaMkII.cpp
Mitchell Jackson
COSC 1337
Prof Betts

Simple text-based adventure program. Highly linear.
Made from program written for Test1.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void displayBackpack();

void preeroom();
void R1();
void R2();
void R3A();
void R3B();
void R4A();
void R5A();
void R3B();
void R4B();
void R5BA();
void R5BB();

void BE1();
void BE2();
void E6BA1();
void E6BA2();
void R6BB();
void E6BB1();
void E6BB2();
void EA1();
void EA2();
void EA3();

void gameLoop();

vector<string> backpack;
char answer;

int main()

{
    //Start Game!
    cout << "\n\tWelcome, Treasure Hunter. You have been tasked with finding\n"
         << "\thaunted items from the abandoned 'Medici Manor'.\n\n"
         << "\t\tDo you wish to begin? y/n...";
    cin >> answer;
    if(answer == 'n'){
        BE1();
    } else {
        preeroom();
    }
    return 0;
}

void preeroom(){
    cout << "\n\tYou stand before the Haunted Villa. Lightning flashes in the distance."
                     << "\n\t\tDo you wish to enter? y/n...";
    cin >> answer;
    if(answer == 'n'){
        BE1();
    } else {
        R1();
    }
}

void displayBackpack(){
    //display backpack contents
    cout << "\n\t\tYour backpack contains:\n";
    for( string obj : backpack){
    cout << "\t\t" << obj << endl;
    }
}

void R1(){
    cout << "\n\tYou enter a large foyer, obviously meant for receiving guests. A layer of dust covers lavish furniture."
    << "\n\tOne object has no dust on it - an old ring-dial telephone..."
    << "\n\n\t\tDo you wish to collect it? y/n...";
    cin >> answer;
    if(answer == 'n'){
        cout << "\n\n\t\t You do not collect the Phone.";
    } else {
        cout << "\n\n\t\tYou collect the phone.";
        backpack.push_back("Telephone");
        displayBackpack();
    }
    R2();
}

void R2(){
    cout << "\n\tThere is only one door leading from the foyer. Do you go through it?";
    cin >> answer;
    if(answer == 'n'){
        BE2();
    }
    cout << "\n\tYou enter a large hallway. Somehow, the gas lamps lighting it are fueled and flickering."
         << "\n\tWalking down the corridor, you spot a shiny brass key..."
         << "\n\n\t\tDo you wish to collect it? y/n...";
    cin >> answer;
    if(answer == 'n'){
        cout << "\n\n\t\t You do not collect the Key.";
    } else {
        cout << "\n\n\t\tYou collect the Key.";
        backpack.push_back("Brass Key");
        displayBackpack();
    }
    cout << "\n\t There are two doors leading from the foyer: one looks old and dirty, and the other new and clean."
         << "\n\tWhich door do you take? a, or b?";
    cin >> answer;
    if(answer == 'a'){
        cout << "\n\tYou enter the old, dirty door.";
        R3A();
    } else {
        cout << "\n\tYou enter the new, clean door.";
        R3B();
    }
}

void R3A(){
    cout << "\n\n\tYou enter what looks like a nursery."
         << "\n\tThe walls are painted in soft blues and a crib is in the corner."
         << "\n\tInside the crib is a tape player, softly playing a lullaby..."
         << "\n\tDo you wish to collect it? y/n...";
    cin >> answer;
    if(answer == 'n'){
        cout << "\n\n\t\t You do not collect the Tape.";
    } else {
        cout << "\n\n\t\tYou collect the Tape.";
        backpack.push_back("Tape");
        displayBackpack();
    }
    cout << "\n\tOnly one door leads from the nursery - the one behind you has mysteriously closed and locked."
         << "\n\tDo you open the door? y/n...";
    cin >> answer;
    if(answer == 'n'){
        BE2();
    } else {
        R4A();
    }
}

void R4A(){
    cout << "\n\n\tYou open the door and step into a sprawling courtyard."
         << "\n\tDead trees line the perimeter, which is defined by a huge wrought iron fence."
         << "\n\tYou hear a low growl from the other side of the courtyard."
         << "\n\tA huge, 3-headed dog stands 30 feet from you, growling menacingly."
         << "\n\tYou check behind you, but alas, the door you came from has closed on its own."
         << "\n\tYou don't have many options. You can try to use an item you have, fight/tame the dog yourself, \n\tor run."
         << "\n\tWhich will you do? a, b, or c...";
    cin >> answer;
    if(answer == 'a'){
        if(find(backpack.begin(), backpack.end(), "Tape")== backpack.end()){
            cout << "\n\tYou don't have the right item!";
            EA3();
        } else {
            cout << "\n\tYou reach into your bag and pull out the Tape recorder."
                 << "\n\tYou hit play, and the dog's heads all droop - soon it is asleep."
                 << "\n\tYou see a gate behind the dog, and slowly walk towards it.";
            EA1();
        }
    } else if(answer == 'b'){
        if(find(backpack.begin(), backpack.end(), "Telephone")== backpack.end()){
            cout << "\n\tYou don't have the right item!";
            EA3();
        } else {
            cout << "\n\tYou reach into your bag and pull out the Telephone."
                 << "\n\tYou throw it at the dog! by a sheer miracle, the parts of the phone"
                 << "\n\tFlail out and hit all three dog heads. It drops."
                 << "\n\tYou see a gate behind the dog, and slowly walk towards it, picking up the phone on the way.";
            EA1();
        }
    } else {
        EA3();
    }
}

void EA1(){
    cout << "\n\n\tYou've escaped!"
         << "\n\tYou have haunted item(s):\n";
    for( string obj : backpack){
        cout << "\t\t" << obj << endl;
    }
    cout << "\n\t\tYour client is pleased! Both your fame as a treasure hunter and the number in you bank account"
         << "\n\t\tincrease substantially.";
    gameLoop();
}


void EA3(){
    cout << "\n\tYou take not but a step and the dog is on you: you are eaten.";
    gameLoop();
}

void R3B(){
    cout << "\n\tYou enter what seems to be a bathroom! It is completely spotless."
    << "\n\tYou hear a noise coming from the toilet... on inspection, there is a music box playing"
    << "\n\thalf submerged in the water."
    << "\n\n\t\tDo you wish to collect it? y/n...";
    cin >> answer;
    if(answer == 'n'){
    cout << "\n\n\t\tYou don't collect the Music Box.";
    }else{
    cout << "\n\n\t\tYuck.";
    cout << "\n\n\t\tYou collect the Music Box.";
    backpack.push_back("Music Box");
    displayBackpack();
    }
    cout << "\n\tIn what can only be described as a design flaw, one door leads out of the bathroom."
         << "\n\tDo you continue? y/n...";
    cin >> answer;
    if(answer == 'n'){
        BE2();
    } else {
        R4B();
    }
}

void R4B(){
    cout << "\n\tYou enter what seems to be a study."
        << "\n\tIncredibly, a fire crackles in a fireplace on the far side of the room."
        << "\n\tSitting on a desk in the middle of the study is an eyeball suspended in a translucent green fluid."
        << "\n\tIt turns and looks at you."
        << "\n\n\t\tDo you wish to collect it? y/n...";
    cin >> answer;
    if(answer == 'n'){
    cout << "\n\n\t\tYou do not collect the Eyeball.";
    } else {
    cout << "\n\n\t\tHow spooky.";
    cout << "\n\n\t\tYou collect the Spooky Eyeball.";
    backpack.push_back("Spooky Eyeball");
    displayBackpack();
    }
    cout << "\n\tTwo doors out of the room. You turn and see the door you entered by is closed."
         << "\n\tTesting the handle, you find it is locked... You turn to the other doors."
         << "\n\tOne door seems to be pulling air into a small slot in its middle"
         << "\n\tWhile the other has green ooze secreting from around it."
         << "\n\tWhich door do you choose, a or b?";
    cin >> answer;
    if(answer == 'a'){
        cout << "\n\n\t\t You enter the ominous door with the slot.";
        R5BA();
    } else {
        cout << "\n\n\t\t You enter the door with slime around it.";
        R5BB();
    }
}

void R5BA(){
    cout << "\n\tYou walk down a long set of stairs, lit but flickering candles on the walls."
         << "\n\tWhen you reach the bottom, you see a dimly lit room filled with tables and scrolls."
         << "\n\tThe walls are covered in cobwebs."
         << "\n\tAt the very center is a large, leather bound tome. Surrounding it is a pentagram."
         << "\n\tYou open the tome and see spells and rituals detailed meticulously."
         << "\n\n\tThis is obviously the abandoned lair of a warlock."
         << "\n\n\tThere are two choices apparent to you: Use the artifacts and gain power, or destroy the unholy place."
         << "Which fate do you choose - a, or b?";
    cin >> answer;
    if(answer == 'a'){
        cout << "\n\n\t\tYou choose to become an unholy warlock!";
        E6BA1();
    } else {
        cout << "\n\n\t\tYou decide these powers are evil and light the basement afire.";
        E6BA2();
    }
}

void R5BB(){
    cout << "\n\tYou enter a kitchen."
         << "\n\tOn a granite countertop lies what appears to be a huge slab of pork."
         << "\n\tLooking around, you see no utensils or containers..."
         << "\n\n\t\tDo you wish to collect it? y/n...";
    cin >> answer;
    if(answer == 'n'){
        cout << "\n\n\t\tYou do not collect the Slab of Meat.";
    } else {
        cout << "\n\n\t\tIf a ghost doesn't get you, botulism might.";
        cout << "\n\n\t\tYou collect the Slab of Meat.";
        backpack.push_back("Slab of Meat");
        displayBackpack();
    }
    cout << "\n\tYou don't even bother checking the door behind you, and stride towards the only other portal in the room."
         << "\n\tDo you continue? y/n...";
    cin >> answer;
    if(answer == 'n'){
        BE2();
    } else {
        R6BB();
    }
}


void E6BA1(){
    cout << "\n\tThe first ritual you perform is that which elongates your life."
         << "\n\tYou remain in the mansion, needing its contents for your spells."
         << "\n\tA long life of evil Wizardry awaits you.";
    gameLoop();
}

void E6BA2(){
    cout << "\n\tYou light the place ablaze, seeking to destroy the evil within."
         << "The entire mansion burns down - you are prosecuted for destruction of historical property."
         << "While in prison, you write a book about your experiences. It's a bestseller!"
         << "You go on to become a famous author with your own TV show.";
    gameLoop();
}

void R6BB(){
    cout << "\n\tYou enter what can only be a Gothic laboratory."
         << "\n\tSitting on a table are a huge assortment of vials and beakers, odd substances, and a book..."
         << "\n\tYou open the book and see a series of procedures, with ingredients including..."
         << "\n\tA slab of meat, an eyeball and various chemicals which seem to be provided on the table."
         << "\n\n\t\tDo you wish to perform the procedure? y/n...";
         cin >> answer;
         if(answer == 'n'){
            BE2();
         } else {
            if((find(backpack.begin(), backpack.end(), "Slab of Meat")!= backpack.end())&& (find(backpack.begin(), backpack.end(), "Spooky Eyeball")!=backpack.end())){
                E6BB1();
            } else {
                E6BB2();
            }
         }
}

void E6BB1(){
    cout << "\n\n\t\tYou perform the experiment and are left with a slab of meat, now bright green,"
             << "\n\t\twith an eyeball in it. It smells horrible."
             << "\n\t\tSuddenly the meat slab jumps up! It has protruded several meat-tentacles."
             << "\n\t\tIt points at your backpack and holds out a green... hand?"
             << "\n\t\tYou hand it the backpack.";
    //check if Player has all items
    if((find(backpack.begin(), backpack.end(), "Telephone")== backpack.end())||(find(backpack.begin(), backpack.end(), "Music Box")== backpack.end())
       ||(find(backpack.begin(), backpack.end(), "Brass Key")== backpack.end())){
        cout << "\n\t\tThe Meat Golem looks inside and shakes its head. It gestures for you to turn back.";
        cout << "\n\t\tYou must be missing something!";
        BE2();
    } else {
        cout << "\n\t\tThe Meat Golem takes out the music box, winds it up, and dances a tiny jig to the tune."
             << "\n\t\tIt then takes out the key and waddles over to a door, unlocking it. It gestures for you to leave."
             << "\n\n\t\tYou leave."
             << "\n\tYou have escaped the mansion!"
             << "\n\n\t\tYou have one very, very haunted telephone."
             << "\n\t\tYour client is pleased! Both your fame as a treasure hunter and the number in you bank account"
             << "\n\t\tincrease substantially.";
        gameLoop();
    }
}

void E6BB2(){
    cout << "\n\n\t\tYou don't have all the ingredients!";
    BE2();
}

void BE1(){
    //Player Chickens out
    cout << "\n\tFearing for your safety, you decide not to explore the Villa."
    << "\n\n\tYour reputation as a Treasure Hunter is ruined." << endl;
    gameLoop();
}

void BE2(){
    //if the player tries to leave before traversing all rooms
    cout << "\n\tAs you try to escape, the ghost of an ancient Italian Banker attacks you."
    << "\n\n\t\tYou perish, pelted to death by spectral coins."
    << "\n\n\t\tYour death adds to the manor's reputation...";
    gameLoop();
}

void gameLoop(){
    cout << "\n\n\t\tGame over!" << endl << endl;
    cout << "\n\n\t\tDo you want to play again? y/n...";
    cin >> answer;
    if(answer == 'y'){
        backpack.clear();
        preeroom();
    } else {
        cout << "\n\tThanks for playing!";
        exit(0);
    }
}
