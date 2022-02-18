all: affichageTexte.o main.o types.o listeChainee.o interfaceGraphique.o
	gcc $^ -o Dessinator_009 -Wall `pkg-config --libs gtk+-3.0` `pkgconfig --libs cairo` -lm
    
interfaceGraphique.o: interfaceGraphique.c
	gcc -c interfaceGraphique.c -o interfaceGraphique.o -Wall
`pkg-config --cflags gtk+-3.0` `pkg-config --cflags cairo

hephaistos.o: hephaistos.c
	gcc -c hephaistos.c -o hephaistos.o -Wall 

%.o: %.c %.h
	gcc -c $< -o $@ -Wall

.PHONY: clean

clean:
	rm *.o
	rm Dessinator_009