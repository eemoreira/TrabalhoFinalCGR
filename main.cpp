#include "util.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"



int main() {
    // world
    hittable_list world;

    world.add(make_shared<sphere>(point3(-1, 0, -1.5), 0.5));
    world.add(make_shared<sphere>(point3(-0.8, 0.5, -2), 0.5));

    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1600;
    cam.samples_per_pixel = 3;
    cam.max_iterations = 50;
    cam.render(world);
}
