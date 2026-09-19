class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closex;
        if(x2 < xCenter) closex = x2;
        else if(x1 > xCenter) closex = x1;
        else closex = xCenter;

        int closey;
        if(y2 < yCenter) closey = y2;
        else if(y1 > yCenter) closey = y1;
        else closey = yCenter;

        int dx = xCenter - closex;
        int dy = yCenter - closey;
        return (dx * dx) + (dy * dy) <= (radius * radius);
    }
};