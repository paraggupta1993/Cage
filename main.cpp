//Author : Parag Gupta
//Email : paraggupta1993@gmail.com

#include<cstdio>
#include<gtk/gtk.h>
#include<webkit/webkit.h>
using namespace std ;

GtkWidget *window;
WebKitWebView *webView;

void setUri( GtkWidget* widget , GtkWidget* entry ){
    const gchar *entry_text;
    entry_text = gtk_entry_get_text ( GTK_ENTRY (entry));
    webkit_web_view_load_uri(webView, entry_text );
}
void full( void )
{
     gtk_window_fullscreen( GTK_WINDOW (window) );
}
void unfull( void ){
        gtk_window_unfullscreen (GTK_WINDOW( window) );
        gtk_main_quit ();
}
void destroy (void)
{
    gtk_main_quit ();
}

int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);
    
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *entry = gtk_entry_new();
    GtkWidget *browserLabel = gtk_label_new("Cage-0.1");
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    g_signal_connect ( window , "destroy",G_CALLBACK(destroy), NULL);

    GtkWidget *endButton = gtk_button_new_with_label ("End-Test");
    GtkWidget *goButton = gtk_button_new_with_label("Go");

    g_signal_connect( endButton , "clicked",G_CALLBACK ( unfull ), NULL);
    
    //--------Browser code------------------
    
    // Create a browser instance
    webView = WEBKIT_WEB_VIEW(webkit_web_view_new());

    // Create a scrollable area, and put the browser instance into it
    GtkWidget *scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(scrolledWindow), GTK_WIDGET(webView));
    
    gtk_entry_set_max_length (GTK_ENTRY (entry), 500);
    
    //Setting Homepage 
    gtk_entry_set_text (GTK_ENTRY (entry), "https://www.hackerrank.com/");
    webkit_web_view_load_uri(webView, "https://www.hackerrank.com/");
    
    
    g_signal_connect( goButton, "clicked",G_CALLBACK ( setUri ), entry);
    
    //--------------Laying out------------- 
    gtk_box_pack_start(GTK_BOX(hbox), endButton  , FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), entry , TRUE, TRUE , 5);
    gtk_box_pack_start(GTK_BOX(hbox), goButton , FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), browserLabel  , FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox  , FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), scrolledWindow , TRUE, TRUE, 5);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show_all (window);
    
    //------------------------
    gtk_window_set_keep_above( GTK_WINDOW( window ) , true);
    full(); //fullscreen 
    
    gtk_main ();

    return 0;
}


