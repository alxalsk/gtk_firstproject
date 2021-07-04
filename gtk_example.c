#include<gtk.h>

static void clicked_button(GtkWidget *widget, gpointer data)
{
	g_print("OK this %s is clicked", (gchar *)data);
}
int main(int argc, char *argv[])
{
	GtkWidget *window, *label, *button;
	gtk_init( &argc, &argv );
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 300, 300);
//		label = gtk_label_new("Hello World");
	button = gtk_button_new_with_label("Hi!");
//	gtk_container_add(GTK_CONTAINER(window), label);
	gtk_container_add(GTK_CONTAINER(window), button);
//	gtk_label_set_text(GTK_LABEL(label), "World Hello");
	gtk_widget_show_all(window);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button,"clicked",G_CALLBACK(clicked_button), (gpointer)"button0");
	gtk_main();
	return 0;
}
