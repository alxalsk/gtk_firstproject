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
	GtkWidget *window,*entry,*label, *spin, *scroll;
//	void do_clicked(GtkButton *b);
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
	spin= GTK_WIDGET(gtk_builder_get_object(builder, "spin"));
	CHECK(spin)
	scroll= GTK_WIDGET(gtk_builder_get_object(builder, "scroll"));
	CHECK(scroll)
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}

G_MODULE_EXPORT void do_clicked(GtkButton *b)
{
	gtk_label_set_text(GTK_LABEL(label), (const gchar *)"This is clicked!");
}
G_MODULE_EXPORT void do_radio1(GtkRadioButton *b)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b)))
		gtk_label_set_text(GTK_LABEL(label), (const gchar *)"Radio1 is active");
}
G_MODULE_EXPORT void do_check(GtkCheckButton *b)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b)))
		gtk_label_set_text(GTK_LABEL(label), (const gchar *)"check is active");
	else
		gtk_label_set_text(GTK_LABEL(label), (const gchar *)"check is not active");
}
G_MODULE_EXPORT void do_clicked1(GtkButton *b)
{
	gint i = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
	char s[20];
	snprintf(s, sizeof(s),"the number %d",i);
	gtk_label_set_text(GTK_LABEL(label),(const gchar *) s);
}
G_MODULE_EXPORT void do_switch(GtkSwitch *b)
{
	if(gtk_switch_get_active(b))
		gtk_label_set_text(GTK_LABEL(label),(const gchar *)"switch is active");
	else
		gtk_label_set_text(GTK_LABEL(label), (const gchar *)"switch is unactive");
}
/*G_MODULE_EXPORT void do_entry(GtkEntry *b)
{
	char s[50];
	snprintf(s, sizeof(s),"entry=%s", gtk_entry_get_text(b));
//	gtk_label_set_text(GTK_LABEL(label),s);
}*/
G_MODULE_EXPORT void do_combo(GtkComboBox *b)
{
	printf("this has changed");
}
G_MODULE_EXPORT void do_color(GtkColorButton *b)
{
	GdkRGBA color;
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(b), &color);
	printf("%f \n",color.red);
	printf("%f \n",color.green);
	printf("%f \n",color.blue);
	printf("%f \n",color.alpha);
}
G_MODULE_EXPORT void do_file_cb(GtkFileChooserButton *b)
{
	gtk_label_set_text(GTK_LABEL(label),gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(b)));
}
G_MODULE_EXPORT void do_font(GtkFontButton *b)
{
	gtk_label_set_text(GTK_LABEL(label),gtk_font_chooser_get_font(GTK_FONT_CHOOSER(b)));
}
G_MODULE_EXPORT void do_volume(GtkVolumeButton *b)
{
	char s[20];
	snprintf(s,sizeof(s),"vol%f\n",gtk_scale_button_get_value(GTK_SCALE_BUTTON(b)));
	gtk_label_set_text(GTK_LABEL(label),(const gchar *)s);
}
G_MODULE_EXPORT void do_scroll(GtkScrollbar *b)
{
	char s[20];
	snprintf(s,sizeof(s),"scroll%f\n",gtk_range_get_value(GTK_RANGE(b)));
	gtk_label_set_text(GTK_LABEL(label),(const gchar *)s);
}
G_MODULE_EXPORT void do_entry(GtkEntry *b)
{
	gtk_label_set_text(GTK_LABEL(label),gtk_entry_get_text(b));
}
G_MODULE_EXPORT void do_click2(GtkButton *b)
{
	char filename[] = "img004bis.jpg";
	//gtk_editable_delete_text(GTK_EDITABLE(entry), 0, -1);
	gtk_label_set_text(GTK_LABEL(label), "identify -format %%wx%%h \"img004bis.jpg\" \n");
}
