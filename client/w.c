#include <wayland-client.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

struct wl_compositor* comp;
struct wl_surface* srfc;
struct wl_buffer* bfr;
struct wl_shm* shm;


int32_t alc_shm(uint64_t sz) {
  int8_t name[8];
  name[0] = '/';
  name[7] = 0;
  for (uint8_t i=1;i<6;i++) {
    name[i] = (rand() & 23) +97;
  }
  int32_t fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, S_IWUSR | S_IRUSR | S_IWOTH | S_IR
//
void reg_glob(void* data, struct wl_registry* reg, uint32_t name, const char* intf,uint32_t v) {
    printf("Global Object registered: %u (interface: %s, version: %u)\n", name, intf,v);

  if (!strcmp(intf,wl_compositor_interface.name)) {
      comp = wl_registry_bind(reg, name, &wl_compositor_interface,4);
  }
}
//when a global is no longer needed
void reg_glob_rem(void* data, struct wl_registry* reg, uint32_t name) {
}

struct wl_registry_listener reg_list = {
  .global = reg_glob,
  .global_remove = reg_glob_rem
};


int8_t main() {
  //connecting to the wayland server, if running any
  struct wl_display* disp = wl_display_connect(0);
  //
  struct wl_registry* reg = wl_display_get_registry(disp);
  wl_registry_add_listener(reg, &reg_list, 0);
  wl_display_roundtrip(disp);
  
  //always close you disp, clean your objects
  wl_display_disconnect(disp);
  
  return 0;
}
//loading the registries
