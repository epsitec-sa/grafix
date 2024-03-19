//	AntiGrain.Win32/agg_color_interpolator.h
//
//	Copyright © 2005 Maxim Shemanarev (http://www.antigrain.com)
//	Copyright © 2005-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#include "antigrain.h"
#include "structures.h"

/*****************************************************************************/

namespace agg
{
    class color_interpolator_rgba8
    {
    public:
        color_interpolator_rgba8(agg::rgba8 c1, agg::rgba8 c2, unsigned len) :
            m_r(c1.r, c2.r, len),
            m_g(c1.g, c2.g, len),
            m_b(c1.b, c2.b, len),
            m_a(c1.a, c2.a, len)
        {
        }

        void operator ++ ()
        {
            ++m_r; ++m_g; ++m_b; ++m_a;
        }

        rgba8 color() const
        {
            return rgba8(m_r.y(), m_g.y(), m_b.y(), m_a.y());
        }

    private:
        dda_line_interpolator<16> m_r;
        dda_line_interpolator<16> m_g;
        dda_line_interpolator<16> m_b;
        dda_line_interpolator<16> m_a;
    };
    
	
	// Rendering a square with color interpolation between its corners
    // The colors of the corners are ordered CCW started from bottom-left,
    // assuming that the Y axis goes up.
    //------------------------------------------------------------------
    template<class Renderer>
    void color_rect_rgba8(Renderer& r, int x, int y, int dx, int dy,
                          rgba8 c1, rgba8 c2, rgba8 c3, rgba8 c4)
    {
        int i, j;
        color_interpolator_rgba8 cy1(c1, c4, dy);
        color_interpolator_rgba8 cy2(c2, c3, dy);
        for(i = 0; i < dy; ++i)
        {
            color_interpolator_rgba8 cx(cy1.color(), cy2.color(), dx);
            for(j = 0; j < dx; ++j)
            {
                r.copy_pixel(x + j, y + i, cx.color());
                ++cx;
            }
            ++cy1;
            ++cy2;
        }
    }
}

/*****************************************************************************/
