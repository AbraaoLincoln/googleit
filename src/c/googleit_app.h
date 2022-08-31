#ifndef __GOOGLEITAPP_H
#define __GOOGLEITAPP_H

#include <gtk/gtk.h>

#define GOOGLEITAPP_TYPE (googleit_app_get_type())
G_DECLARE_FINAL_TYPE (GoogleitApp, googleit_app, GOOGLEIT, APP, GtkApplication)

GoogleitApp *googleit_app_new(void);

#endif