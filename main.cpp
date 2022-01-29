#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

int main()
{
    srand(time(0));

    int cell, cellCount = 0, purchased = 0, fcEnd, snowyFirst, waitTwo = 2;
    bool fish = false, hubOne = false, snowy = false, invalid = false;
    string holdString;

    string invalidCells[94] = {
        "Geyser: Cell on path",             //#0
		"Geyser: Scout flies",
		"Geyser: Open blue eco door",
		"Geyser: Climb the cliff",          //#3
		"Sandover: Yakows",                 //#4
		"Sandover: Mayor orbs",
		"Sandover: Uncle orbs",
		"Sandover: Oracle orbs",
		"Sandover: Oracle orbs",
		"Sandover: Scout flies",
		"Sentinel: Pelican",
		"Sentinel: Cannon",
		"Sentinel: Middle sentinel",
		"Sentinel: Green eco cloggers",
		"Sentinel: Seagulls",
		"Sentinel: Flut flut egg",
		"Sentinel: Explore the beach",
		"Sentinel: Scout flies",
		"FJ: Mirrors",
		"FJ: Fish",                         //#19
		"FJ: Swim to island",
		"FJ: Locked blue eco door",
        "FJ: Scout flies",                  //#22
		"FJ: Top of tower",                 //#23
		"FJ: Plant boss",                   //#24
		"FJ: Open blue eco vent",           //#25
		"Misty: Pillar platform",           //#26
		"Misty: Cannon",
		"Misty: Ambush",
		"Misty: On top of ship",
		"Misty: Zeppelins",
		"Misty: Wooden ramp",
		"Misty: Scout flies",
		"Misty: Muse",                      //#33
		"FC: Scout flies",                  //#34
		"FC: Reach end",                    //#35
		"Rock Village: Gambler orbs",       //#36
		"Rock Village: Geologist orbs",
		"Rock Village: Warrior orbs",
		"Rock Village: Oracle orbs",
		"Rock Village: Oracle orbs",
		"Rock Village: Scout flies",
		"Basin: Moles",
		"Basin: Race",
		"Basin: Over the lake",
		"Basin: Plants",
		"Basin: Purple rings",
		"Basin: Blue rings",
		"Basin: Flying lurkers",
		"Basin: Scout flies",
		"LPC: Pipe cell",
		"LPC: Circle room",
		"LPC: Puzzle",
		"LPC: Piggyback tm",
		"LPC: Far side of pool",
		"LPC: Bottom of city",
		"LPC: Raise the chamber",
		"LPC: Scout flies",
		"Boggy: Tether cell 1",
		"Boggy: Tether cell 2",
		"Boggy: Tether cell 3",
		"Boggy: Tether cell 4",
		"Boggy: Rats",
		"Boggy: Ride Flut Flut",
		"Boggy: Ambush",
		"Boggy: Scout flies",
		"Mountain pass: Klaww",
		"Mountain pass: Secret cell",
		"Mountain pass: Reach end",
		"Mountain pass: Scout Flies",       //#69
		"VC: Miners",                       //#70
		"VC: Miners",
		"VC: Miners",
		"VC: Miners",
		"VC: Oracle orbs",
		"VC: Oracle orbs",
		"VC: Secret cell",
		"VC: Scout flies",
		"Spider Cave: Gnawing lurkers",
		"Spider Cave: Dark eco crystals",
		"Spider Cave: Dark cave",
		"Spider Cave: Top of robot",
		"Spider Cave: Poles",
		"Spider Cave: Spider tunnel",
		"Spider Cave: Platforms",
		"Spider Cave: Scout flies",         //#85
		"Snowy: Yellow vent",               //#86
		"Snowy: Glacier troops",
		"Snowy: Blockers",
		"Snowy: Secret cell",
		"Snowy: Fortress door",
		"Snowy: Fortress",
		"Snowy: Lurker cave",
		"Snowy: Scout flies" };             //#93

    vector<string> validCells;
    vector<string> chosenCells;

    for (int i = 0; i < 4; i++) {               //add Geyser cells to validCells[]
        validCells.push_back(invalidCells[i]);
    }

    do {        //randomise next 72 cells
        invalid = false;

        //Leaving Geyser [check]
        if (cellCount == 4) {
            for (int i = 4; i < 24; i++) {      //add all pre-fire canyon cells excluding Misty & temple cells to validCells[]
                validCells.push_back(invalidCells[i]);
            }
        }
        //Picked up 20 cells [check]
        if (cellCount == 20) {
            for (int i = 34; i < 36; i++) {     //add Fire Canyon flies and end cell to validCells[]
                validCells.push_back(invalidCells[i]);
            }
        }

        //Cell randomiser; picks random cell from validCells[] and adds it to chosenCells[]
        cell = rand() % validCells.size();
        chosenCells.push_back(validCells[cell]);
        holdString = validCells[cell];
        cellCount++;

        //Purchase [check]
        if (holdString.find("orbs") != std::string::npos) {
            purchased++;
        }
        //Not enough orbs [check]
        if ((!hubOne && !fish && purchased == 4) || (!fish && !snowy && purchased == 13)) {
            chosenCells.erase(chosenCells.end());
            cellCount--;
            purchased--;
            invalid = true;
        }
        //Fish [check]
        if (validCells[cell] == "FJ: Fish") {
            for (int i = 26; i < 34; i++) {     //add all Misty cells to validCells[]
                validCells.push_back(invalidCells[i]);
            }
            fish = true;
        }
        //Top of temple [check]
        if (validCells[cell] == "FJ: Top of tower") {
            for (int i = 24; i < 26; i++) {     //add temple cells to validCells[]
                validCells.push_back(invalidCells[i]);
            }
        }
        //First Snowy cell [check]
        if (waitTwo == 0 && !snowy && cell >= validCells.size() - 8) {
            snowyFirst = cellCount - 1;         //set variable for future use; randomising red sage and printing correctly
            snowy = true;
        }
        //Two cells after leaving hub 1 [check]
        if (hubOne && waitTwo > 0) {
            if (waitTwo == 1) {
                for (int i = 86; i < 94; i++) { //add all Snowy cells to validCells[]
                    validCells.push_back(invalidCells[i]);
                }
            }
            waitTwo--;
        }
        //Leaving hub 1 [check]
        if (validCells[cell] == "FC: Reach end") {
            for (int i = 36; i < 86; i++) {     //add all hub 2/3 cells excluding Snowy to validCells[]
                validCells.push_back(invalidCells[i]);
            }
            fcEnd = cellCount - 1;              //set variable for future use; randomising red sage and printing correctly
            hubOne = true;
        }

        if (!invalid) {
            validCells.erase(validCells.begin() + cell);
        }
    }
    while (cellCount < 72);

    //Red Sage randomiser: Red Sage is watched/skipped after a random cell that is, or is after, FC end, but at least 3 cells before the first Snowy cell
    int redSage = rand() % (snowyFirst - fcEnd - 2) + (fcEnd);

    //Final Print
    cout<<endl<<endl<<"Final list:"<<endl;
    for (int i=0;i < chosenCells.size(); i++) {

        if (chosenCells[i-1] == "FJ: Fish") {
            cout<<"----Misty Island unlocked----"<<endl;
        }
        if (i == 20) {
            cout<<"----Fire Canyon unlocked----"<<endl;
        }
        if (chosenCells[i-1] == "FC: Reach end") {
            cout<<"----Hub 2/3 unlocked----"<<endl;
        }
        if (i == redSage + 1) {
            cout<<"[Watch/Skip Red Sage cutscene now]"<<endl;
        }
        if (i == redSage + 3) {
            cout<<"----Snowy Mountain unlocked----"<<endl;
        }

        cout<<i+1<<". "<<chosenCells[i]<<endl;
    } //

    return 0;
}
