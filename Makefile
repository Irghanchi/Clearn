cflag := -Werror -Wall -lm
libs := `pkg-config --libs raylib`
include := `pkg-config --cflags raylib`
run: ll.c
	@clear
	@cc -o ll $(cflag) $(libs) $(include) gun.c
	@./ll
	@rm -rf ll
