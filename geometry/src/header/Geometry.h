#pragma once

#include <string>

/**
 * Describes point with two integer coordinates 'x' and 'y'
*/
struct Point {
    int x;
    int y;
};

/**
 * Base class for figures
*/
class Figure {
    public:

        /**
         * Creates Figure with center (x; y) and border color c
         * Figure is invisible
         * 
         * @param c Border color
         * @param x x of center
         * @param y y of center
        */
        Figure(int c, int x, int y);
        
        virtual ~Figure();

        /**
         * Returns point that represents center
         * 
         * @return Center of Figure
         * 
         * @see Point
        */
        Point getCenter();

        /**
         * Moves center if the Figure is visible
         * 
         * @param dx x offset
         * @param dy y offset
        */
        void move(int dx, int dy);
        
        /**
         * Sets border color if Figure is visible
         * 
         * @param c New border color
        */
        virtual void setBorderColor(int c);
        
        /**
         * Returns border color
         * 
         * @return Current border color
        */
        int getBorderColor() const;
        
        /**
         * Changes Figure's visibility
         * 
         * @param isVisible Visibility flag
        */
        void setVisible(bool isVisible = true);
        
        /**
         * Returns visibility of the Figure
         * 
         * @return True if the Figure is visible and else in other case
        */
        bool isVisible() const;
        
        /**
         * Calculates params of the Figure
         * 
         * @param perimeter Param for result. Perimeter of the Figure
         * @param area Param for result. Area of the Figure
        */
        virtual void calcParams(float& perimeter, float& area) const = 0;

    protected:
        
        /**
         * Coordinates of center
        */
        int x,y;
        
        /**
         * Draws the Figure
        */
        virtual void draw() const = 0;

    private:
        
        /**
         * Border color
        */
        int c;
        
        /**
         * Visibility flag
        */
        bool visible;
};

/**
 * Represents pair of Romb's sizes: width and height
*/
struct RombSizes {
    double width;
    double height;
};

/**
 * Determines how to render Romb
*/
class RombDrawer {
    public:
        /**
         * Renders romb with given params
         * 
         * @param x x of center
         * @param y y of center
         * @param widht Width of romb
         * @param height Height of romb
         * @param borderColor Border color
         * @param fillColor Fill color. Value -1 means that the romb is empty
        */
        virtual void draw(int x, int y, double width, double height, int borderColor, int fillColor = -1) = 0;
};

/**
 * Prints Romb's paramethers into std::cout
*/
class TextRombDrawer: public RombDrawer {
    public:

        /**
         * @see RombDrawer#draw
        */
        virtual void draw(int x, int y, double width, double height, int borderColor, int fillColor = -1);
};

/**
 * Creates file with SVG representation of romb
*/
class SVGRombDrawer: public RombDrawer {
    public:
        
        /**
         * @param inputFile File with template code. Assumes that the file contains ${FIGURE} placeholder
         * @param outputFile File where SVG code will be stored
        */
        SVGRombDrawer(std::string inputFile = "./template.html", std::string outputFile="./Romb.html");

        /**
         *   ------------>
         *   |
         *   |
         *   |
         *   |
         *   |
         * Y V 
         * 
         * @see RombDrawer#draw
        */
        virtual void draw(int x, int y, double width, double height, int borderColor, int fillColor = -1);
    
    private:

        /**
         * Template file
        */
        std::string INPUT_FILE;

        /**
         * Output file
        */
        std::string OUTPUT_FILE;

        /**
         * Generates SVG tag that represents romb with given params
         * 
         * @param x x of center
         * @param y y of center
         * @param widht Width of romb
         * @param height Height of romb
         * @param borderColor Border color
         * @param fillColor Fill color. Value -1 means that the romb is empty
         * 
         * @return String with SVG tag
        */
        std::string generateTag(int x, int y, double width, double height, int borderColor, int fillColor);
};

/**
 * Represents romb. Subclass of Figure
 * 
 * @see Figure
*/
class Romb: public Figure {
    public:
        
        /**
         * Creates Romb object with given params
         * If width or height not correct, then they both set to 1
         * 
         * @param c Border color
         * @param x x of center
         * @param y y of center
         * @param widht Width of romb
         * @param height Height of romb
         * @param drawer Object that draws romb
         * 
         * @see #sisesIsCorrect
         * @see Figure#Figure
         * @see RombDrawer
        */
        Romb(int c, int x, int y, double width, double height, RombDrawer* drawer = new TextRombDrawer()): Figure(c, x, y) {
            if (sizesIsCorrect(width, height)) {
                this->width = width;
                this->height = height;
            }

            this->drawer = drawer;
        }

        virtual ~Romb();

        /**
         * Override
         * 
         * @see Figure#calcParams
        */
        virtual void calcParams(float& perimeter, float& area) const;

        /**
         * Returns RombSizes structur with width and height
         * 
         * @return Sizes of the Romb
         * 
         * @see RombSizes 
        */
        RombSizes getSizes();
        
        /**
         * Sets sizes if they are correct
         * 
         * @param width New width
         * @param height New height
         * 
         * @see #sizesIsCorrect
        */
        void setSizes(double width, double height);

    protected:

        /**
         * Params of Romb
        */
        double width = 1, height = 1;

        /**
         * Object that represents Romb
        */
        RombDrawer* drawer;
        
        /**
         * Override
         * Calls draw method of drawer
         * 
         * @see #drawer
         * @see Figure#draw
        */
        virtual void draw() const;

    private:

        /**
         * Checks given width and height
         * 
         * @param width Width to check
         * @param height Height to check
         * @return true if width and height > 0, else in other case
        */
        bool sizesIsCorrect(double width, double height);
};

/**
 * Represents filled romb. Subclass of Romb
 * 
 * @see Romb
 * @see Figure
*/
class FilledRomb: public Romb {
    public:

        /**
         * Creates Fiiled Romb with given params
         * 
         * @param c Border color
         * @param fillColor Fill color
         * @param x x of center
         * @param y y of center
         * @param widht Width of romb
         * @param height Height of romb
         * @param drawer Object that represents romb
         * 
         * @see Romb#Romb
        */
        FilledRomb(
            int c,
            int fillColor,
            int x,
            int y,
            double width,
            double height,
            RombDrawer* drawer = new TextRombDrawer()
        ): Romb(c, x, y, width, height, drawer) {
            this->fillColor = fillColor;
        }

        ~FilledRomb();

        /**
         * Returns fill color
         * 
         * @return Fill color
        */
        int getFillColor();

        /**
         * Sets fill color
         * 
         * @param c New fill color
        */
        void setFillColor(int c);

        /**
         * Override
         * 
         * Sets border color if it isn't equal to current fill color
         * 
         * @param c New border color
         * 
         * @see Figure#setBorderColor
        */
        virtual void setBorderColor(int c);

    protected:
        
        /**
         * Override
         * 
         * Calls method draw of drawer
         * 
         * @see #drawer
         * @see Romb#draw
         * @see Figure#draw
        */
        virtual void draw() const;

    private:

        /**
         * Fill color
        */
        int fillColor;
};
