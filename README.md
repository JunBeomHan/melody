# melody
Simple melody Cue!

# Example
```C
#include <stdio.h>
#include "melody/melody.h"


int main() {
    initMelody(UBUNTU_OS);
    
    playMelody(DO);
    playMelody(RE);
    playMelody(MI);
    playMelody(FA);
    playMelody(SOL);
    playMelody(LA);
    playMelody(SI);
    playMelody(DO_OCTAVE);
}
```
