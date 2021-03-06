CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = main.o Item.o BDEffect.o PotionEffect.o WAEffect.o BAEffect.o WDEffect.o BA.o BD.o PH.o Potion.o RH.o WA.o WD.o DragonHoard.o Gold.o MerchantHoard.o Normal.o Small.o Drow.o Goblin.o Player.o Shade.o Troll.o Vampire.o Dwarf.o Dragon.o Elf.o Enemy.o Halfling.o Human.o Merchant.o Orc.o Character.o Chamber.o Floor.o GameGrid.o Cell.o Door.o FloorTile.o GridObjects.o Passages.o StairWay.o Wall.o Level.o Subject.o textDisplay.o Student.o Nomair.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
