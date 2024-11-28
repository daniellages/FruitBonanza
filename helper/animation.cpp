#include "animation.hpp"

// Simple animation of a progress bar, purely visual
void progressBar(uint32_t miliSeconds) {
    uint32_t segmentedMiliSeconds;
    
    if(miliSeconds % 3 == 0) {

        segmentedMiliSeconds = miliSeconds / 3;
        std::cout << "------------------------\r" << std::flush;

        // Stage 1
        Sleep(segmentedMiliSeconds);
        std::cout << "\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0----------------\r" << std::flush;

        // Stage 2
        Sleep(segmentedMiliSeconds);
        std::cout << "\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0--------\r" << std::flush;

        // Stage 3
        Sleep(segmentedMiliSeconds);
        std::cout << "\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\n";

    } else if(miliSeconds % 4 == 0) {

        segmentedMiliSeconds = miliSeconds / 4;
        std::cout << "\n";
        std::cout << "------------------------\r" << std::flush;

        // Stage 1
        Sleep(segmentedMiliSeconds);
        std::cout << "\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0------------------\r" << std::flush;

        // Stage 2
        Sleep(segmentedMiliSeconds);
        std::cout << "\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0------------\r" << std::flush;

        // Stage 3
        Sleep(segmentedMiliSeconds);
        std::cout << "\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0------\r" << std::flush;

        // Stage 4
        Sleep(segmentedMiliSeconds);
        std::cout << "\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\u25A0\n";
    } else {    // Default
        Sleep(miliSeconds);
    }
}