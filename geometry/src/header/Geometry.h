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
        
        virtual void draw() const = 0;
        
        int x,y; // базовая точка

    private:
        
        int c; // цвет
        
        bool visible;
};
