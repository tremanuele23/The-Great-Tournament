# The Great Tournament
This is my first game, made in C++ mostly by using OOP. 
It's a simple text-based RPG structured as a tournament between medieval-like warriors.
# How to run
You need to create a project and add these files to it. Make sure the audios are in the same folder as the .exe file. In Code:BLocks (the IDE I used) go to Project > Build Options > Linker Settings, and add "winmm" in the Link libraries field.
# How fights work. 
  Each weapon has its damage value. Each class is characterized by a value, called Factor. 
  In order to attack, you have to repeatedly click a key from your keyboard. You can make 10 clicks at most. The damage you do is given by the clicks you make * the damage of your weapon * the factor of your class.
  Only works on Windows.
