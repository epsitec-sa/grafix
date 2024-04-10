#pragma once

#include "agg_pixfmt_rgba.h"
/* #include "agg_renderer_mclip.h" */
#include "agg_renderer_base.h"
#include "agg_span_allocator.h"
#include "agg_scanline_bin.h"

#include "platform/agg_platform_support.h"

const agg::pix_format_e pix_format = agg::pix_format_bgra32;
typedef agg::pixfmt_bgra32              pixfmt;
typedef agg::pixfmt_bgra32_pre          pixfmt_pre;
#define pixfmt_gamma agg::pixfmt_bgra32_gamma
typedef agg::rgba8                      color_type;
typedef agg::order_bgra                 component_order;
typedef agg::renderer_base<pixfmt>      renderer_base_t;
typedef agg::renderer_base<pixfmt_pre>  renderer_base_pre_t;
/* typedef agg::renderer_mclip<pixfmt>     renderer_base_t; */
/* typedef agg::renderer_mclip<pixfmt_pre> renderer_base_pre_t; */
typedef agg::span_allocator<color_type> span_alloc_type_t;

typedef agg::renderer_scanline_bin_solid<renderer_base_t> renderer_bin_t;
