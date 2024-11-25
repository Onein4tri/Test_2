#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/Unicode.hpp>  // For Unicode::snprintfFloat if needed
#include <cmath> // Math library for sine calculation

#define SCALE_FACTOR 57

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();

    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent(); // for external event to able to insert values into the graph
    void updatePressureGraph();

    virtual void graph1Clicked(AbstractDataGraph::GraphClickEvent value)override;
    virtual void graph1Dragged(AbstractDataGraph::GraphDragEvent value)override;




private:
        int tickCounter;    // Tracks the update interval, control how often to insert into the graph
        int lastIndex;

protected:
         void updateInfoWidgetPosition();
};

#endif // SCREEN2VIEW_HPP
