lcc := $(LCC_BIN)

game.gb: _build
	$(lcc) src/main.c -o _build/game.gb

_build: clean
	mkdir _build
	
clean:
	rm -rf _build
