#include <pebble.h>

static Window *window;
static TextLayer *text_layer;

static void window_load(Window *window) {
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);
	
	text_layer = text_layer_create((GRect) { .origin = { 0, 70 }, .size = { bounds.size.w, 100 } });
	text_layer_set_text(text_layer, "Hola Mundo");
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

static void window_unload(Window *window) {
	text_layer_destroy(text_layer);
}

static void init(void) {
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	const bool animated = true;
	window_stack_push(window, animated);
}

static void deinit(void) {
	window_destroy(window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}