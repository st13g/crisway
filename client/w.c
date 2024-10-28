#include <wayland-client.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


struct wl_compositor* comp;

void reg_glob(void* data, struct wl_registry* reg, uint32_t name, const char* intf,uint32_t v) {
//    printf("Global Object registered: %u (interface: %s, version: %u)\n", name, intf,v);

  if (!strcmp(intf,wl_compositor_interface.name)) {
      comp = wl_registry_bind(reg, name, &wl_compositor_interface,4);
  }
}

void reg_glob_rem(void* data, struct wl_registry* reg, uint32_t name) {
}

struct wl_registry_listener reg_list = {
  .global = reg_glob,
  .global_remove = reg_glob_rem
};


int8_t main() {
  struct wl_display* disp = wl_display_connect(0);
  struct wl_registry* reg = wl_display_get_registry(disp);
  wl_registry_add_listener(reg, &reg_list, 0);
  wl_display_roundtrip(disp);
  
  wl_display_disconnect(disp);
  
  return 0;
}
