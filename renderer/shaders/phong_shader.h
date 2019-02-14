#ifndef PHONG_SHADER_H
#define PHONG_SHADER_H

#include "../core/api.h"

typedef struct {
    vec4_t ambient_factor;
    vec4_t emission_factor;
    vec4_t diffuse_factor;
    vec4_t specular_factor;
    float shininess;
    const char *emission_texture;
    const char *diffuse_texture;
    const char *specular_texture;
} phong_material_t;

typedef struct {
    vec3_t position;
    vec2_t texcoord;
    vec3_t normal;
} phong_attribs_t;

typedef struct {
    vec3_t position;
    vec2_t texcoord;
    vec3_t normal;
} phong_varyings_t;

typedef struct {
    vec3_t light_dir;
    vec3_t camera_pos;
    mat4_t model_matrix;
    mat4_t model_it_matrix;
    mat4_t viewproj_matrix;
    /* from material */
    vec4_t ambient_factor;
    vec4_t emission_factor;
    vec4_t diffuse_factor;
    vec4_t specular_factor;
    float shininess;
    texture_t *emission_texture;
    texture_t *diffuse_texture;
    texture_t *specular_texture;
} phong_uniforms_t;

/* low-level api */
vec4_t phong_vertex_shader(void *attribs, void *varyings, void *uniforms);
vec4_t phong_fragment_shader(void *varyings, void *uniforms);

/* high-level api */
model_t *phong_create_model(const char *mesh_filename, mat4_t transform,
                            phong_material_t material);
void phong_release_model(model_t *model);
phong_uniforms_t *phong_get_uniforms(model_t *model);
void phong_draw_model(model_t *model, framebuffer_t *framebuffer);

#endif