#include "GameGrid.h"
#include "Drow.h"
#include "Goblin.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"

#include "Level.h"
#include "Player.h"
#include "textDisplay.h"
#include "Floor.h"

using namespace std;

GameGrid::GameGrid() {}

//GameGrid::~GameGrid(){
//    delete pc;
//}

void GameGrid::init(){
    l = make_shared<Floor>();
    shared_ptr<Floor> f = dynamic_pointer_cast<Floor>(l);
    f->init(pc);
    l = f;
}

void GameGrid::move(string dir){
    pc->move(dir);
    if (pc->hasReachedShairs()) {
        pc = pc->getTrue();
        if(pc->goUpstairs() > 5) {
            win();
        }
        init();
    }
}

void GameGrid::use(string dir) {
    pc = l->use(pc, dir);
}

void GameGrid::attack(string dir){
    pc->attack(dir,pc);
}

void GameGrid::setRace(char race){
    switch (race) {
        case 's': pc = make_shared<Shade>(); break;
        case 'd': pc = make_shared<Drow>(); break;
        case 'v': pc = make_shared<Vampire>(); break;
        case 'g': pc = make_shared<Goblin>(); break;
        case 't': pc = make_shared<Troll>(); break;
        default: throw "unknown race"; break;
    }
}

void GameGrid::freeze(){
    l->setFrozen();
}

//void GameGrid::clearGrid(){
//    delete l;
//}

ostream &operator<<(std::ostream &out, const GameGrid &g){
    out << *(g.l);
    g.pc->PrintMessages();
    return out;
}

void GameGrid::win() {
    printWin();
}

void GameGrid::printStart() {
    cout << "CC3KCC3  CC3KCC3  KCC3KCC  CC  CC3" << endl;
    cout << "KCC3KCC  KCC3KCC   KCC3KC  KC  KC" << endl;
    cout << "3K       3K            3K  3K C3K" << endl;
    cout << "C3       C3            C3  C3 CC" << endl;
    cout << "CC       CC         C3KCC  CCKC" << endl;
    cout << "KC       KC         CC3KC  KC 3K" << endl;
    cout << "3K       3K            3K  3K  3K" << endl;
    cout << "C3       C3            C3  C3  C3" << endl;
    cout << "CC3KCC3  CC3KCC3   CC3KCC  CC  CC3" << endl;
    cout << "KCC3KCC  KCC3KCC  3KCC3KC  KC   CC" << endl << endl;
    cout << "Welcome to CC3K produced by Yinong Wang, Raymond Tan, and Qifan Zhu." << endl;
    cout << "To start the game, choose a race: s, d, v, g, t" << endl;
}

void GameGrid::printWin() {
    cout << "CONGRAT  CONGRAT  CONGRAT  CONGRAT  CONGRAT    NGR   SCONGRA  SCONGRA" << endl;
    cout << "GRATSCO  GRATSCO  GRATSCO  GRATSCO  GRATSCO    ATS   NGRATSC  NGRATSC" << endl;
    cout << "TS       TS   GR  TS   GR  TS       TS   GR    CON      CO    AT" << endl;
    cout << "ON       ON   TS  ON   TS  ON       ON   TS    GRAT     GR    CO" << endl;
    cout << "RA       RA   ON  RA   ON  RA SCON  RASCON    ATSCO     TS    GRATSC" << endl;
    cout << "SC       SC   RA  SC   RA  SC NGRA  SCNGRA    CO GR     ON    TSCONGR" << endl;
    cout << "NG       NG   SC  NG   SC  NG   SC  NG  TS    GR TS     RA         TS" << endl;
    cout << "AT       AT   NG  AT   NG  AT   NG  AT  ON    TS  NG    SC         ON" << endl;
    cout << "CONGRAT  CONGRAT  CO   AT  CONGRAT  CO  RA   CON RAT    NG    SCONGRA" << endl;
    cout << "GRATSCO  GRATSCO  GR   CO  GRATSCO  GR   CO  GRA SCO    AT    NGRATSC" << endl;
    cout << endl << endl;
    cout << "OU   NY  U WINYO  WW   OU        WI   UU   YO  WW  YOU WIN" << endl;
    cout << "WI   UU  INYOU W  NY   WI        YO   IN   WW  NY  WWINYOU" << endl;
    cout << "YO   IN  OU   NY  U    YO        WW   OU   NY  UU  NY   WI" << endl;
    cout << "WW   OU  WI   UU  IN    W        NY   WI   UU  IN  UU   YO" << endl;
    cout << "NYOU WI  YO   IN  OU   NY        UW   YO   IN  OU  IN   WW" << endl;
    cout << "U WINYO  WW   OU  WI   UU        IN   WW   OU  WI  OU   NY" << endl;
    cout << "  YOU    NY   WI  YO   IN        OU   NY   WI  YO  WI   UU" << endl;
    cout << "   WI    UU   YO  WW   OU        WI   UW   YO  WW  YO   IN" << endl;
    cout << "   YO    INYOU W  NYOU WI        YOU WINYOUW   WY  WW   OU" << endl;
    cout << "   W     OU WINY  U WINYO         WINYOU WIW   UU  NY   WI" << endl << endl;
    cout << "Press r to restart the game" << endl;
}

void GameGrid::printLose() {
    cout << "ERGAMEE    RGA    OVERGAMEEEVV  GAME OV       OVERGAM   O   GA    OVERGA  E OVERG" << endl;
    cout << "OVERGAM    VER    E OVERGAEEOO  ERGAME        E OVERG  ME   ER   ME OVE   AME OVE" << endl;
    cout << "E          COV    AM   VE   ME  OV            AM   VE   AM  OV   GA       RG    O" << endl;
    cout << "AM         MEOO   RG    O   GA  E             RG    O   RG ME    ER       VE   ME" << endl;
    cout << "RG  EOO   RGAME   VE   ME   ER  AME OV        VE   ME   VE GA    OVERGA    O ERGA" << endl;
    cout << "VE  AME   VE GA    O   GA   OV  RGAME          O   GA    OVER    E OVER   ME OVER" << endl;
    cout << "O    GA   O  ER   ME   ER   E   VE            ME   ER    E OV    AM       GA   O" << endl;
    cout << "ME   ER   ME  VE  GA   OV   AM   O            GA   OV    AME     RG       ER  ME" << endl;
    cout << "GAME OV  RGA E O  ER   E    RG  ME OVER       ERGAME     RGA     VERGAME  OV  GA" << endl;
    cout << "ERGAMEE  VER AME  OV   AM   VE  GAME O        OVERGAM    VER      OVERG   E    RG" << endl << endl;
    cout << "Press r to restart the game" << endl;
}
