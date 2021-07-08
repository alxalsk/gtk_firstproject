#include<gtk.h>
typedef struct maxi{
	GtkWidget *widget1, *widget2;
} *maxiwidget;
static void clicked_button(GtkWidget *widget, gpointer data)
{
	        if (gtk_entry_get_text(GTK_ENTRY(((maxiwidget)data)->widget1)) == "Hello")
                gtk_button_clicked(GTK_BUTTON(((maxiwidget)data)->widget2));
}
int main(int argc, char *argv[])
{
	GtkWidget *window, *button, *hbox, *entry;
	maxiwidget g = NULL;
	gtk_init( &argc, &argv );
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 300, 300);
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 00);
	button = gtk_button_new_with_mnemonic("_Hi!");
	entry = gtk_entry_new();
	g->widget1 = entry;
	g->widget2 = button;
	gtk_widget_set_size_request(button, 100, 100);
	gtk_container_add(GTK_CONTAINER(window), hbox);
	gtk_box_pack_start(GTK_BOX(hbox), entry, 0, 0, 00);
	gtk_box_pack_start(GTK_BOX(hbox), button, 0, 0, 0);

	gtk_widget_show_all(window);
	
	g_signal_connect(entry, "activate", G_CALLBACK(clicked_button), (gpointer)g);
	g_signal_connect(button, "clicked", G_CALLBACK(clicked_button), (gpointer) g);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
	return 0;
}
