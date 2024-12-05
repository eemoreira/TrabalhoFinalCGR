#include "util.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"



int main() {
    // world
    hittable_list world;

    auto material_ground             = make_shared<lambertian>(color(0.3, 0.3, 0.3));
    auto material_solid_blue         = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_solid_red          = make_shared<lambertian>(color(1, 0, 0));
    auto material_solid_orange       = make_shared<lambertian>(color(1, 0.375, 0));
    auto material_solid_yellow       = make_shared<lambertian>(color(1, 1, 0));
    auto material_solid_almost_black = make_shared<lambertian>(color(0.1, 0.1, 0.1));
    auto material_metal_left         = make_shared<metal>(color(0.8, 0.8, 0.8));
    auto material_metal_right        = make_shared<metal>(color(0.8, 0.1, 0.8));
    auto material_metal_small        = make_shared<metal>(color(1.0, 1.0, 1.0));

    world.add(make_shared<sphere>(point3(-0.3, -0.3, -0.5), 0.2, material_solid_orange));
    world.add(make_shared<sphere>(point3(1.5, 1.2, -2), 0.6, material_solid_yellow));

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( -1,    0.0, -2.5),   0.5, material_solid_red));
    world.add(make_shared<sphere>(point3( 0,    -0.4, -1.5),   0.1, material_solid_blue));
    world.add(make_shared<sphere>(point3( 0,    -0.2, -1.5),   0.1, material_metal_small));
    world.add(make_shared<sphere>(point3( 0,     0.0, -1.5),   0.1, material_solid_red));
    world.add(make_shared<sphere>(point3(-1.5,   0.0, -1.5),   0.5, material_metal_left));
    world.add(make_shared<sphere>(point3( 1,    0.0, -1.0),   0.5, material_metal_right));
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 3840;
    /* cam.image_width = 1600; */
    cam.samples_per_pixel = 100;
    cam.max_iterations = 50;
    cam.render(world);
}
