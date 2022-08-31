#include <gtk/gtk.h>
#include "googleit_app.h"
#include "appwindow.h"

struct _GoogleitApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE(GoogleitApp, googleit_app, GTK_TYPE_APPLICATION);

static void googleit_app_init (GoogleitApp *app){}

static void googleit_app_activate (GApplication *app) {
  AppWindow *win;

  win = app_window_new(GOOGLEIT_APP (app));
  gtk_application_add_window( GTK_APPLICATION(app), GTK_WINDOW (win));
}

static void googleit_app_class_init (GoogleitAppClass *class){
  G_APPLICATION_CLASS(class)->activate = googleit_app_activate;
}

GoogleitApp * googleit_app_new (void){
  return g_object_new (GOOGLEITAPP_TYPE,
                       "application-id", "org.gtk.exampleapp",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}