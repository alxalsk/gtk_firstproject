#include<gtk.h>
#include<string.h>
	static GtkWidget *entry;
	static GtkWidget *button;
static void function(GtkWidget *widget, gpointer data)
{
	if(!strcmp(gtk_entry_get_text(GTK_ENTRY(entry)), (gchar *)"Hello"))
		gtk_button_clicked(GTK_BUTTON(button));
}
int main(int argc, char **argv)
{
	gtk_init(&argc,&argv);
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button            = gtk_button_new_with_label("Hi!");
	entry             = gtk_entry_new();
	GtkWidget *grid   = gtk_grid_new();

	gtk_grid_attach(GTK_GRID(grid),entry,0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),button,1,0,1,1);
	gtk_container_add(GTK_CONTAINER(window),grid);

	gtk_widget_show_all(window);

	g_signal_connect(entry,"activate",G_CALLBACK(function), NULL);
	g_signal_connect(button,"clicked", G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	gtk_main();

	return 0;
}
