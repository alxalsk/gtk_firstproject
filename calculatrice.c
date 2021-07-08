#include<gtk.h>
#include<stdio.h>
#include<stdlib.h>
        static  GtkWidget *entry1;
        static  GtkWidget *entry2;
static void do_calculation(GtkWidget *widget,gpointer data);
int main(int argc, char **argv)
{
	gtk_init(&argc,&argv);
	GtkWidget *window  = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *grid    = gtk_grid_new();
	GtkWidget *button  = gtk_button_new_with_label("Calculate");
	GtkWidget *label   = gtk_label_new(NULL);
	entry1             = gtk_entry_new();
	entry2             = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid),entry1,0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),entry2,1,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),button,2,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),label ,3,0,1,1);
	gtk_container_add(GTK_CONTAINER(window),grid);

	gtk_widget_show_all(window);

	g_signal_connect(button,"clicked"    ,G_CALLBACK(do_calculation),label);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit) ,NULL);
	gtk_main();
	return 0;
}
static void do_calculation(GtkWidget *widget,gpointer data)
{
        char str[50];
        int n1 = atoi(gtk_entry_get_text(GTK_ENTRY(entry1)));
        int n2 = atoi(gtk_entry_get_text(GTK_ENTRY(entry2)));
        snprintf(str, sizeof(str), "the result is %d", n1+n2);
        gtk_label_set_text(GTK_LABEL(data), (const gchar *)str);
}

