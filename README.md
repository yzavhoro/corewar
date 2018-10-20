# corewar

What is Corewar?
- Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.
	
- The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding, etc...
	
- The game ends when all the processes are dead. The winner is the last player reported to be “alive”.

This project can be broken down into three distinctive parts:
- The assembler: this is the program that compiles champions and translates them from the assembly language into “Bytecode”.
	Bytecode is a machine code, which will be directly interpreted by the virtual machine.
	
- The virtual machine: It’s the “arena” in which champions are being executed. It offers various functions, all of which will be useful for the battle of the champions.
	
- The champion: actually, ours (jane.s (yes, that's my name)) is so simle that I don't wanna discribe it, so I added some good ones for you to enjoy their fight.

#### USAGE:
```
make
./asm champions/[bot_name].s
./corewar
```

Virtual machine (corewar) has it's own usage which will be displayed to you.
Enjoy!