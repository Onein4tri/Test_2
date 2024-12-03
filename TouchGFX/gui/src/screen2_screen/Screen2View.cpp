
#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Unicode.hpp>  // If using Unicode::snprintfFloat

#include <stdint.h>  // for uint16_t
#include<math.h>

#include "../../../../STM32CubeIDE/Application/User/Core/PressureSensor.hpp"
#include <texts/TextKeysAndLanguages.hpp>



// Access the global pressure variable from main.c
extern uint16_t scaled_pressure;
extern float pressure_mmhg;
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
	  //sineGraph.addDataPoint(static_cast<int>(pressure_mmhg)- SCALE_FACTOR);y
	int y_position = -1*pressure_mmhg/7; //100 - ((pressure_mmhg - (-200)) / (200 - (-200))) * 200; // Assuming mmHg range is -200 to 200
	sineGraph.addDataPoint(y_position );

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
