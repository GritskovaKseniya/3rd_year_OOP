#include <sstream>
#include <fstream>
#include <string>

#include "../header/Geometry.h"
#include "../header/utils.h"

SVGRomb::SVGRomb(
    int c,
    int x,
    int y,
    double width,
    double height,
    std::string inputFile,
    std::string outputPath,
    std::string ouputFilenamePrefix
): Romb::Romb(c, x, y, width, height) {
    INPUT_FILE = inputFile;
    OUTPUT_PATH = outputPath;
    OUTPUT_FILE_PREFIX = ouputFilenamePrefix;
}

std::string SVGRomb::generateTag() const{
    std::stringstream tag;
    tag << "<polyline points=\""
    << x << "," << y - height/2 << " "
    << x + width/2 << "," << y << " "
    << x << "," << y + height/2 << " "
    << x - width/2 << "," << height/2 << " "
    << x << "," << y - height/2
    << "\" stroke-width=\"1\" stroke=\"rgb(0,0,0)\" fill-opacity=\"0.0\" />";

    return tag.str();
}

void SVGRomb::draw() const {
    std::string tag = generateTag();

    std::ifstream input(INPUT_FILE);
    std::string html(static_cast<std::stringstream const&>(std::stringstream() << input.rdbuf()).str());
    input.close();

    findAndReplaceAll(html, "${FIGURE}", tag);

    std::ofstream output(OUTPUT_PATH + "/" + OUTPUT_FILE_PREFIX + "_" + getCurrentDateAndTime() + ".html");
    output << html;
    output.close();
}
