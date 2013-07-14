name=lesson35


all:$(name).o


$(name).o : $(name).cpp
	g++ -o $(name) $(name).cpp -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
clean :
	rm -rf $(name) $(name).o
