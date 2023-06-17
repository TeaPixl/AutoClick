// AutoClick
// PLEASE NOTE: Computer-generated code in this file
// Code is maintained by Logan Allen
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(ms) Sleep(ms)
#else
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

void leftClick() {
#ifdef _WIN32
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
#else
    Display* display = XOpenDisplay(NULL);
    XTestFakeButtonEvent(display, Button1, True, 0);
    XTestFakeButtonEvent(display, Button1, False, 0);
    XFlush(display);
    XCloseDisplay(display);
#endif
}

void rightClick() {
#ifdef _WIN32
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
#else
    Display* display = XOpenDisplay(NULL);
    XTestFakeButtonEvent(display, Button3, True, 0);
    XTestFakeButtonEvent(display, Button3, False, 0);
    XFlush(display);
    XCloseDisplay(display);
#endif
}

void displayLogo() {
    printf("  AutoClick\n");
    printf("  A computer-generated autoclicker\n");
    printf("\n");
    printf(" /\\_/\\  \n");
    printf("( o.o ) \n");
    printf(" > ^ <  \n");
    printf("\n");
}

int main() {
    displayLogo();

    double clicksPerSecond = 10.0; // Default clicks per second
    double clickDuration = 5.0;    // Default duration is 5 seconds
    int clickType = 0;             // 0 for left click, 1 for right click

    printf("Enter the number of clicks per second: ");
    scanf("%lf", &clicksPerSecond);

    printf("Enter the click duration in seconds: ");
    scanf("%lf", &clickDuration);

    printf("Enter the click type (0 for left click, 1 for right click): ");
    scanf("%d", &clickType);

    printf("Clicking!\n");
    sleep(5);

    double clickInterval = 1000.0 / clicksPerSecond;
    int totalClicks = (int)(clicksPerSecond * clickDuration);

    for (int i = 0; i < totalClicks; i++) {
        if (clickType == 0) {
            leftClick();
        } else if (clickType == 1) {
            rightClick();
        }

        SLEEP_MS((int)clickInterval);
    }

    printf("Exiting!\n");

    return 0;
}
