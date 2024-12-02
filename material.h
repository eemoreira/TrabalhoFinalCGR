#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"

class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const {
        return false;
    }
};

class lambertian : public material {
    public:
        lambertian(color wit) : whiteness(wit) {}
        bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
            auto scatter_direction = rec.normal + random_unit_vector();
            if (scatter_direction.near_zero()) scatter_direction = rec.normal;
            scattered = ray(rec.p, scatter_direction);
            attenuation = whiteness;
            return true;
        }
    private:
        color whiteness;
};

class metal : public material {
    public:
        metal(color wit) : whiteness(wit) {}
        bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
            auto reflected = reflect(r_in.direction(), rec.normal);
            scattered = ray(rec.p, reflected);
            attenuation = whiteness;
            return true;
        }
    private:
        color whiteness;
};

#endif
