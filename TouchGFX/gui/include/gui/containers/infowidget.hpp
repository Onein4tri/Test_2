#ifndef INFOWIDGET_HPP
#define INFOWIDGET_HPP

#include <gui_generated/containers/infowidgetBase.hpp>

class infowidget : public infowidgetBase
{
public:
    infowidget();
    virtual ~infowidget() {}

    virtual void initialize();

    void updateString( int value);
protected:
};

#endif // INFOWIDGET_HPP
