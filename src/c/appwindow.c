#include <gtk/gtk.h>

#include "googleit_app.h"
#include "appwindow.h"

static GoogleitApp *googleitApp;

struct _AppWindow{
  GtkApplicationWindow parent;
  GtkWidget *searchbar;
};

G_DEFINE_TYPE(AppWindow, app_window, GTK_TYPE_APPLICATION_WINDOW);

static void open_on_broswer(GtkEntry *entry, AppWindow *win) {
    const char *term = gtk_entry_get_text(entry);

    if(strlen(term) != 0) {
        char *googleUrl = "https://www.google.com/search?q=";
        char finalUrl[500];
        snprintf(finalUrl, sizeof(finalUrl), "%s'%s'", googleUrl, term);
        g_print("term to search is: %s\n", term);
        g_print("the final url is: %s\n", finalUrl);
        char command[600];
        snprintf(command, sizeof(command), "%s%s%s", "xdg-open ", finalUrl, " &> /dev/null");
        g_print("the command is: %s\n", command);
        system(command);   
    }

    g_application_quit(G_APPLICATION(googleitApp));
}

static void app_window_init (AppWindow *win){
    gtk_widget_init_template (GTK_WIDGET(win));
}

static void
app_window_class_init (AppWindowClass *class){
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                               "/googleit/src/resources/window.ui");
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS (class), AppWindow, searchbar);
    gtk_widget_class_bind_template_callback(GTK_WIDGET_CLASS (class), open_on_broswer);
}

AppWindow * app_window_new (GoogleitApp *app) {
    googleitApp = app;
    return g_object_new (APP_WINDOW_TYPE, "application", app, NULL);
}