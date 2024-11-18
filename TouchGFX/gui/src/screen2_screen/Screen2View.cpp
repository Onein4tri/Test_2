#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Unicode.hpp>  // If using Unicode::snprintfFloat

#include <stdint.h>  // for uint16_t

#include "../../../../STM32CubeIDE/Application/User/Core/PressureSensor.hpp"


// Access the global pressure variable from main.c
extern uint32_t scaled_pressure;



Screen2View::Screen2View() : tickCounter(0)  // Initialize variables
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    sineGraph.clear();                   // Clear the graph initially

}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::updatePressureGraph()
{
	  sineGraph.addDataPoint(static_cast<int>(scaled_pressure)- 57);

}

void Screen2View::handleTickEvent()
{
    tickCounter++;

    if (tickCounter % 2 == 0)  // Adjust frequency of update as needed
    {
    	updatePressureGraph();

    }
}
