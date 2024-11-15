#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Unicode.hpp>  // If using Unicode::snprintfFloat

#include <stdint.h>  // for uint16_t

#include "../../../../STM32CubeIDE/Application/User/Core/PressureSensor.hpp"



// Declare the ReadPressureData function as extern
extern void ReadPressureData(uint16_t *pressure);



Screen2View::Screen2View() : tickCounter(0), angle(0.0f)  // Initialize variables
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

void Screen2View::handleTickEvent()
{
    tickCounter++;

    if (tickCounter % 2 == 0)  // Adjust frequency of update as needed
    {
    	// Read the pressure data and add it to the graph
    	ReadPressureData(reinterpret_cast<uint16_t*>(&pressureValue));

    	// Add the new data point to the graph
    	sineGraph.addDataPoint(pressureValue);

    	// (Optional) Update any labels if needed
    }
}
