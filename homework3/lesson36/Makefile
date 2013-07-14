name=lesson36
GL=-w -lGL -lGLU -lglut

all:$(name).o


$(name).o : $(name).cpp
	g++ -o $(name) $(name).cpp -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer $(GL)
clean :
	rm -rf $(name) $(name).o
