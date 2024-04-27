prog:texte.o image.o option.o minimap.o jouer.o enemie.o background.o perso.o engmetxt.o fct.o engmei.o en_img.o main.o 
	gcc texte.o image.o option.o minimap.o jouer.o enemie.o background.o perso.o engmetxt.o fct.o engmei.o en_img.o main.o -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
main.o:main.c 
	gcc -c main.c -g
texte.o:texte.c 
	gcc -c texte.c -g
image.o:image.c 
	gcc -c image.c -g
option.o:option.c
	gcc -c option.c -lSDL_mixer  -g
minimap.o:minimap.c
	gcc -c minimap.c -g
jouer.o:jouer.c
	gcc -c jouer.c -lSDL_mixer -g
enemie.o:enemie.c
	gcc -c 	enemie.c -g
background.o:background.c 
	gcc -c background.c -g
perso.o:perso.c
	gcc -c perso.c -g 
engmetxt.o:engmetxt.c
	gcc -c engmetxt.c -g
fct.o:fct.c
	gcc -c fct.c -g 
engmei.o:engmei.c 
	gcc -c engmei.c -g
en_img.o:en_img.c 
	gcc -c en_img.c -g 
