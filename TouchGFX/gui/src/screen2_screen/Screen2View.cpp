
#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Unicode.hpp>  // If using Unicode::snprintfFloat

#include <stdint.h>  // for uint16_t
#include<math.h>
#include <main.h>
#include "../../../../STM32CubeIDE/Application/User/Core/PressureSensor.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include "FreeRTOS.h"
#include "task.h"




// Access the global pressure variable from main.c

extern float pressure_mmhg;


Screen2View::Screen2View() : tickCounter(0), lastIndex(0) // Initialize variables
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    sineGraph.clear();                   // Clear the graph initially
 //   tickCounter = 0;   // Reset the tick counter

}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::updatePressureGraph()
{
	int y_position = static_cast<int>(pressure_mmhg);
		if (y_position > 700)
		    y_position = 700;
		else if (y_position < -50)
		    y_position = -50;

		sineGraph.addDataPoint(y_position );

		 // Reverse sign to match graph display convention
	//	 int y_position = static_cast<int>(-1.0f * pressure_mmhg);

		volatile int debug_y_position = y_position;

	//	static int angle = 0;
	//
	//	    // Generate a sine wave value for testing
	//	    int y_position = static_cast<int>(350 + 350 * sin(angle * M_PI / 180));
	//
	//	    sineGraph.addDataPoint(y_position);
	//
	//	    // Increment angle for next value
	//	    angle = (angle + 10) % 360;;

}



void Screen2View::handleTickEvent()
{
    static TickType_t startTime = 0;         // Tracks when the graph started
    static float nextGraphUpdateTime = 0.0f; // Tracks the next time to update the graph
    const float updateInterval = 1.0f;       // Set update interval in seconds (0.1s for 10 updates per second)

    // Get the current tick count from FreeRTOS( since the system started )
    volatile TickType_t currentTime = xTaskGetTickCount();

    // Initialize startTime on the first call
    if (startTime == 0)
    {
        startTime = currentTime;
    }

    // Calculate elapsed time in seconds
    TickType_t elapsedTicks = currentTime - startTime;
    float elapsedTime = (float)elapsedTicks / configTICK_RATE_HZ; // ( the nr of ticks per sec)

    // Update the graph at the defined interval
    if (elapsedTime >= nextGraphUpdateTime)
    {
        nextGraphUpdateTime += updateInterval; // Increment the next update time by the interval
        updatePressureGraph();                // Call the function to update the graph
    }

    // Optional: Debugging variable for elapsed time
    volatile float debugElapsedTime = elapsedTime; // Check this in the debugger
    volatile int debug_y_position = elapsedTicks;
    tickCounter++; // Increment the tick counter
}


void Screen2View::graph1Clicked(AbstractDataGraph::GraphClickEvent value)
{
	if (value.clickEvent.getType() == ClickEvent::PRESSED){
		lastIndex = value.index;
		updateInfoWidgetPosition();
	}

}

void Screen2View::graph1Dragged(AbstractDataGraph::GraphDragEvent value)
{
	lastIndex = value.index;
	updateInfoWidgetPosition();
}

void Screen2View::updateInfoWidgetPosition(){
	infowidget1.moveTo(
			sineGraph.getX() + sineGraph.indexToScreenX(lastIndex) + sineGraph.getGraphAreaMarginLeft(),
			sineGraph.getY() + sineGraph.indexToScreenY(lastIndex) + sineGraph.getGraphAreaMarginTop());
    infowidget1.updateString(sineGraph.indexToDataPointYAsInt(lastIndex));
}
