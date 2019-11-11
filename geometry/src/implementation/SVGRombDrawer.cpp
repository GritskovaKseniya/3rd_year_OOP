#include <sstream>
#include <fstream>
#include <string>

#include "../header/Geometry.h"
#include "../header/utils.h"

SVGRombDrawer::SVGRombDrawer( std::string inputFile, std::string outputFile) {
    INPUT_FILE = inputFile;
    OUTPUT_FILE = outputFile;
}

std::string SVGRombDrawer::generateTag(int x, int y, double width, double height, int borderColor, int fillColor){
    std::stringstream tag;
    tag << "<polyline points=\""
    << x << "," << y - height/2 << " "
    << x + width/2 << "," << y << " "
    << x << "," << y + height/2 << " "
    << x - width/2 << "," << y << " "
    << x << "," << y - height/2 << "\" "
    << "stroke-width=\"1\" "
    << "stroke=\"rgb(" << borderColor << "," << borderColor <<"," << borderColor << ")\" ";
    
    if (fillColor != -1) {
        tag << "fill=\"rgb(" << fillColor << "," << fillColor << "," << fillColor << ")\" ";
    } else {
        tag << "fill-opacity=\"0.0\" ";
    }
    
    tag << "/>";

    return tag.str();
}

void SVGRombDrawer::draw(int x, int y, double width, double height, int borderColor, int fillColor) {
    std::string tag = generateTag(x, y, width, height, borderColor, fillColor);

    std::ifstream input(INPUT_FILE);
    std::string html(static_cast<std::stringstream const&>(std::stringstream() << input.rdbuf()).str());
    input.close();

    findAndReplaceAll(html, "${FIGURE}", tag);

    std::ofstream output(OUTPUT_FILE, std::ofstream::out | std::ofstream::trunc);
    output << html;
    output.close();
}