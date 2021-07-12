#include<gtk/gtk.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<gtk/gtkx.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define CHECK(widget) \
	if(widget ==NULL) {\
	exit(1);\
}
	GtkWidget *window,*entry,*label;
int main(int argc, char **argv)
{
	gtk_init(&argc,&argv);
	
	GtkBuilder *builder = gtk_builder_new_from_file("gladefile.glade");
	CHECK(builder)
	gtk_builder_connect_signals(builder, NULL);
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	CHECK(window)
	entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
	CHECK(entry)
	label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
	CHECK(label)

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

G_MODULE_EXPORT void do_clicked(GtkButton *b)
{
	gtk_label_set_text(GTK_LABEL(label), (const gchar *)"This is clicked!");
}
