#include <stdlib.h>
#include <gtk/gtk.h>
#include "googleit_app.h"

int main(int argc, char *argv[]) {
    return g_application_run (G_APPLICATION (googleit_app_new()), argc, argv);
}