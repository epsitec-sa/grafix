/*
This file is part of AggUI.

Copyright © 2003-2024, EPSITEC SA, 1400 Yverdon-les-Bains, Switzerland

AggUI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

AggUI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
