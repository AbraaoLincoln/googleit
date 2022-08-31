#include <stdlib.h>
#include <gtk/gtk.h>

static GObject *entry;

static void open_on_broswer(GtkWidget *widget, gpointer data){
    char *term = (char *) gtk_entry_get_text(GTK_ENTRY(entry));

    if(strlen(term) != 0) {
        char *googleUrl = "https://www.google.com/search?q=";
        char finalUrl[500];
        snprintf(finalUrl, sizeof(finalUrl), "%s'%s'", googleUrl, term);
        g_print("term to search is: %s\n", term);
        g_print("term to search is: %s\n", finalUrl);
        char command[600];
        snprintf(command, sizeof(command), "%s%s%s", "xdg-open ", finalUrl, " &> /dev/null");
        system(command);   
    }

    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    GError *error = NULL;

    gtk_init(&argc, &argv);

    /* Construct a GtkBuilder instance and load our UI description */
    builder = gtk_builder_new ();
    if(gtk_builder_add_from_file(builder, "window.ui", &error) == 0) {
    g_printerr ("Error loading file: %s\n", error->message);
    g_clear_error (&error);
    return 1;
    }

    entry = gtk_builder_get_object (builder, "searchTerm");
    g_signal_connect(entry, "activate", G_CALLBACK(open_on_broswer), NULL);

    gtk_main();

    return 0;
}