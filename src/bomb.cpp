#include <raylib.h>

int main()
{
    // Initialization (you may need to adjust the window size)
    InitWindow(800, 600, "Image to C Code Exporter");

    // Load the image from your specified path
    Image img = LoadImage("C:\\Users\\vaay\\tetwist-cmsc123\\src\\star.jpg");

    // Export the image as C code
    ExportImageAsCode(img, "star.h");

    // Unload the image to free memory
    UnloadImage(img);

    CloseWindow(); // Close the Raylib window and deinitialize
    return 0;
}