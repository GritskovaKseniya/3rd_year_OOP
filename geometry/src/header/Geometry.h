#pragma once

class Figure {
    public:

        Figure(int c, int x, int y);
        
        virtual ~Figure();

        void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
        
        void setBorderColor(int c); // установить цвет фигуры – только видимой
        
        int getBorderColor() const; // получить цвет
        
        void setVisible(bool isVisible = true); // показать/спрятать фигуру
        
        bool isVisible() const; // признак видимости
        
        virtual void calcParams(float& perimeter, float& area) const = 0;

    protected:
        
        int x,y; // базовая точка
        
        virtual void draw() const = 0;

    private:
        
        int c; // цвет
        
        bool visible;
};

class Romb: public Figure {
    public:
        
        Romb(int c, int x, int y, double width, double height): Figure(c, x, y) {
            if (sizesIsCorrect(width, height)) {
                this->width = width;
                this->height = height;
            }
        }

        virtual ~Romb();

        virtual void calcParams(float& perimeter, float& area) const;

        double* getSizes();
        
        void setSizes(double width, double height);

    protected:

        virtual void draw() const;

    private:

        double width = 1, height = 1;

        bool sizesIsCorrect(double width, double height);
};
