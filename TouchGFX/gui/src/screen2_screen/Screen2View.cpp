#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Unicode.hpp>  // If using Unicode::snprintfFloat

#include <stdint.h>  // for uint16_t
#include<math.h>

#include "../../../../STM32CubeIDE/Application/User/Core/PressureSensor.hpp"


// Access the global pressure variable from main.c
extern uint16_t scaled_pressure;
Screen2View::Screen2View() : tickCounter(0), lastIndex(0) // Initialize variables
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
	  sineGraph.addDataPoint(static_cast<int>(scaled_pressure)- SCALE_FACTOR);

}

void Screen2View::handleTickEvent()
{
    tickCounter++;

    if (tickCounter % 2 == 0)  // Adjust frequency of update as needed, each 2:nd time insert into the graph
    {
    	updatePressureGraph();

    }
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
