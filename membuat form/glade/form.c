#include <gtk/gtk.h>

void on_window_main_destroy()
{
    gtk_main_quit();
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkBuilder *gtkBuilder;

  window = gtk_application_window_new (app);
  gtkBuilder = gtk_builder_new();
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_builder_add_from_file(gtkBuilder, "form.glade", NULL);
  window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "mainform"));  
  g_object_unref(G_OBJECT(gtkBuilder));

  gtk_widget_show_all (window);
}


int main(int argc, char *argv[])
{
    GtkApplication *app;
    gtk_init(&argc, &argv);
    
    int status;
    
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    
    return status;
}
