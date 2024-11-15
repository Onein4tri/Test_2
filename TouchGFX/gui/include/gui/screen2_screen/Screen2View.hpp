#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/Unicode.hpp>  // For Unicode::snprintfFloat if needed
#include <cmath> // Math library for sine calculation

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();

    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    void updatePressureGraph();  // Now without arguments

private:
        int tickCounter;    // Tracks the update interval
        float angle;        // Current angle for the sine wave
        int pressureValue;        // Store the pressure data here
protected:
};

#endif // SCREEN2VIEW_HPP
