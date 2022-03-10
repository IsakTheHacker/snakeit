#include "handyFunctions.h"

int randIntRange(int min, int max) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

	return dist(rng);
}

const char* char2cstr(const char& c) {
	std::string str = {c};
	return str.c_str();

	//return std::string{c}.c_str();
	/*
		The above code also works but has
	   	a weird syntax LOL

		----------------------------------------------------

	   	History so that I never make the same mistake again:
	   	Before this function existed I used:

	   	(const char*)&c

	   	to convert from char to c str which doesn't work
	   	(probably because we don't have a null termination character)

	   	What happened was that it spit out random characters from memory
	   	we didn't own resulting in VERY strange behaviour:

							  U@
					  U@
				 U@   U@
			 U@  U@   U@       UUUUU@
			 U@  U@   U@       U@  U@
			 U@  U@   U@       U@  U@        UUUUUU@
			 U@                                                oooooooO@
			 U@       U@                     U@   U@
			 U@                    U@        U@
			 U@                              U@
			 UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU@

		(Terminal output)

		The only thing supposed to be here is the snake: "oooooooO"
		The @s and Us should not be here xD
		   
		So there you have it! This took me several hours to figure out so
		I hope someone who finds this code in the future can benefit from this ;)
	*/
}
