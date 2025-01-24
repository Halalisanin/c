#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int number, attempts;
GtkWidget *entry, *output_label, *color_label;

// Function to reset the game
void reset_game() {
    srand(time(0));
    number = rand() % 100 + 1;
    attempts = 0;
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    gtk_label_set_text(GTK_LABEL(output_label), "Guess a number between 1 and 100");
    gtk_widget_set_name(color_label, "default");
}

// Function to set the color of the color_label
void set_color(GtkWidget *widget, const char *color_name) {
    gtk_widget_set_name(widget, color_name);
}

// Callback function for the guess button
void on_guess_button_clicked(GtkWidget *widget, gpointer data) {
    (void) widget; // Mark parameter as unused
    (void) data; // Mark parameter as unused

    const char *guess_text = gtk_entry_get_text(GTK_ENTRY(entry));
    int guess = atoi(guess_text);
    attempts++;

    if (guess > number) {
        gtk_label_set_text(GTK_LABEL(output_label), "Too high! Try again.");
        set_color(color_label, "red");
    } else if (guess < number) {
        gtk_label_set_text(GTK_LABEL(output_label), "Too low! Try again.");
        set_color(color_label, "red");
    } else {
        char result[256];
        snprintf(result, sizeof(result), "Congratulations! You guessed the number in %d attempts.", attempts);
        gtk_label_set_text(GTK_LABEL(output_label), result);
        set_color(color_label, "green");
        return;
    }

    if (abs(guess - number) <= 3) {
        set_color(color_label, "orange");
    }
}

// Callback function for the reset button
void on_reset_button_clicked(GtkWidget *widget, gpointer data) {
    (void) widget; // Mark parameter as unused
    (void) data; // Mark parameter as unused
    reset_game();
}

// Main function
int main(int argc, char *argv[]) {
    GtkWidget *window, *grid, *guess_button, *reset_button;

    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Number Guessing Game");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Connect the destroy signal to gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid and add it to the window
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create a label and entry for user input
    GtkWidget *label = gtk_label_new("Enter your guess:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 1, 1);

    // Create a label for output messages
    output_label = gtk_label_new("Guess a number between 1 and 100");
    gtk_grid_attach(GTK_GRID(grid), output_label, 0, 1, 2, 1);

    // Create a color label to show the light
    color_label = gtk_label_new("");
    gtk_widget_set_size_request(color_label, 200, 50);
    gtk_grid_attach(GTK_GRID(grid), color_label, 0, 2, 2, 1);

    // Create a guess button and connect its clicked signal
    guess_button = gtk_button_new_with_label("Guess");
    g_signal_connect(guess_button, "clicked", G_CALLBACK(on_guess_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), guess_button, 0, 3, 1, 1);

    // Create a reset button and connect its clicked signal
    reset_button = gtk_button_new_with_label("Reset");
    g_signal_connect(reset_button, "clicked", G_CALLBACK(on_reset_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), reset_button, 1, 3, 1, 1);

    // Initialize the game
    reset_game();

    // Apply CSS
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "#red { background-color: red; }\n"
        "#orange { background-color: orange; }\n"
        "#green { background-color: green; }\n"
        "#default { background-color: white; }\n",
        -1, NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(GTK_WIDGET(window));
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Show all widgets
    gtk_widget_show_all(window);

    // Run the main GTK loop
    gtk_main();

    return 0;
}
