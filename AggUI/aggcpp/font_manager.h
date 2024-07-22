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

#include <string>

#include "agg_conv_contour.h"
#include "agg_font_freetype.h"


#include "declspec.h"
#include "pixelfmt.h"


namespace AntigrainCPP {

    class FontManager {

        public:
            typedef agg::font_engine_freetype_int32 font_engine;
            typedef agg::font_engine_freetype_int32::path_adaptor_type path_adaptor_type;

            FontManager();

            bool load_font(const char* font_name);
            void set_font_size(double size);
            void use_outline_mode(bool mode);

            font_engine              m_feng;
            std::string m_current_font_name;
            bool             m_outline_mode;
    };

    extern "C" DECLSPEC FontManager* FontManager_New();

    extern "C" DECLSPEC void FontManager_Delete(FontManager* fm);

    extern "C" DECLSPEC bool FontManager_LoadFont(FontManager* fm,
        const char* font_name
    );

    extern "C" DECLSPEC void FontManager_SetFontSize(FontManager* fm,
        double size
    );
}
