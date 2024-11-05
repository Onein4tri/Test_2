#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View() : tickCounter(0), angle(0.0f)  // Initialize variables
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    sineGraph.clear();             // Clear the graph initially
  //  sineGraph.setRange(-100, 100); // Set Y-axis range
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
        // Calculate the sine value and scale it to fit the Y-axis range
        float sineValue = std::sin(angle) * 100;

        // Add the new data point to the graph
        sineGraph.addDataPoint(static_cast<int>(sineValue));

        // Increment the angle for the next sine calculation
        angle += 0.1f;

        // Reset the angle after a full cycle to avoid overflow
        if (angle >= 4 * M_PI)
            angle -= 4 * M_PI;
    }
}
