#ifndef __APPWINDOW_H
#define __APPWINDOW_H

#include <gtk/gtk.h>
#include "googleit_app.h"


#define APP_WINDOW_TYPE (app_window_get_type())
G_DECLARE_FINAL_TYPE (AppWindow, app_window, APP, WINDOW, GtkApplicationWindow)

AppWindow *app_window_new (GoogleitApp *app);

#endif