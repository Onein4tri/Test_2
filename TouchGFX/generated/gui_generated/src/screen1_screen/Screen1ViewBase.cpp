/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

Screen1ViewBase::Screen1ViewBase() :
    flexButtonCallback(this, &Screen1ViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_BACKGROUNDS_480X272_METEOR_RAIN_ID));
    add(image1);

    scalableImage1.setBitmap(touchgfx::Bitmap(BITMAP_SIGMA_ID));
    scalableImage1.setPosition(0, 0, 480, 272);
    scalableImage1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    add(scalableImage1);

    flexButton1.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton1.setBorderSize(5);
    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(153, 148, 0), touchgfx::Color::getColorFromRGB(204, 167, 0), touchgfx::Color::getColorFromRGB(95, 102, 0), touchgfx::Color::getColorFromRGB(153, 136, 52));
    flexButton1.setIconBitmaps(Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_EXIT_TO_APP_50_50_EDECE6_SVG_ID), Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_EXIT_TO_APP_50_50_DED8CC_SVG_ID));
    flexButton1.setIconXY(0, 0);
    flexButton1.setAction(flexButtonCallback);
    flexButton1.setPosition(430, 222, 50, 50);
    add(flexButton1);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton1)
    {
        //Interaction1
        //When flexButton1 clicked change screen to Screen2
        //Go to Screen2 with screen transition towards East
        application().gotoScreen2ScreenSlideTransitionEast();
    }
}