#include <gui/containers/infowidget.hpp>

infowidget::infowidget()
{

}

void infowidget::initialize()
{
    infowidgetBase::initialize();
}

void infowidget::updateString( int value)
{
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%i", value);
	textArea1.invalidate();

}

