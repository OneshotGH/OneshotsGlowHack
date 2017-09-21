
                   /* @'   @+          @;         @@@@@         @@@@@,                  @                                
                      @@  ;@+          @;         @,  @         @'  @,                  @           @                    
                      @@, @@+ +@@@: @@@@; @@@@    @,  @ @; '@   @'  @, @@@@  @@@@ :@@@' @@@@, @@@@:@@@#                    
                      @,@.@#+ ,. ## @  @; @  @    @@@@@ ,@ @:   @'  @, @` @` @  @ +@ :; @, @; @  @' @.                    
                      @ @@:#+ '@@@# @  @; @@@@    @,  @  @ @    @'  @, @  @` @@@@  @@@  @  @; @  @' @.                     
                      @ '@ #+ @. @# @  @; @  .    @,  @  '@     @;  @, @  @` @  . `` +@ @  @; @  @' @.                      
                      @    #+ @@@@# @@@@; @@@@    @@@@@ :@:     @@@@@. @  @. @@@@ '@@@@ @` @; @@@@' @@+ */             
#include "OneshotsGlowHack.h"
CHackProcess fProcess; // Object made so we can use the class functions
Glow G;
int main() // our start this code runs first.
{
	std::cout << "Oneshots GlowHack. if you wanna use this and call it your own pls make some credits to me." << std::endl;
	fProcess.RunProcess(); // runing RunProcess() that setups everything we need to read and write memory.
	std::cout << "Game Found Starting Glow" << std::endl;
	while (true) // a while loop that we have to run our code over and over until we shut it down.
	{
		G.Run();
		Sleep(1); // Sleep of 1ms so we dont eat to much cpu power.
	}
	
    return 0; 
}

