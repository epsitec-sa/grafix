#include "interface.h"
#include "structures.h"

#include <ippcore.h>
#include <ipp.h>

static void InitIPP()
{
	static bool need_init = true;
	
	if (need_init)
	{
		need_init = false;
		ippStaticInitBest ();
	}
}

AggBuffer* AggBufferNew(unsigned dx, unsigned dy, unsigned bpp)
{
	InitIPP ();
	
	AggBuffer* buffer = new AggBuffer ();
	
	if (buffer)
	{
		buffer->bitmap_dc  = 0;
		buffer->bitmap     = 0;
		buffer->bitmap_old = 0;
		
		buffer->pixmap.create (dx, dy, (agg::org_e) bpp, 0xff);
		buffer->buffer.attach (buffer->pixmap.buf (), buffer->pixmap.width (), buffer->pixmap.height (), buffer->pixmap.stride ());
		buffer->renderer = new AggRendererCommon (buffer->buffer);
		buffer->renderer_pre = new AggRendererCommonPre (buffer->buffer);
	}
	
	return buffer;
}

AggBuffer* AggBufferNewUsingOS(void* hdc, unsigned dx, unsigned dy, unsigned bpp)
{
	InitIPP ();
	
	AggBuffer* buffer = new AggBuffer ();
	
	if (buffer)
	{
		buffer->bitmap_dc  = ::CreateCompatibleDC ((HDC) hdc);
		buffer->bitmap     = buffer->pixmap.create_dib_section (buffer->bitmap_dc, dx, dy, (agg::org_e) bpp, 0xff);
		buffer->bitmap_old = ::SelectObject (buffer->bitmap_dc, buffer->bitmap);
		
		buffer->buffer.attach (buffer->pixmap.buf (), buffer->pixmap.width (), buffer->pixmap.height (), buffer->pixmap.stride ());
		buffer->renderer = new AggRendererCommon (buffer->buffer);
		buffer->renderer_pre = new AggRendererCommonPre (buffer->buffer);
	}
	
	return buffer;
}

void AggBufferResize(AggBuffer* buffer, unsigned dx, unsigned dy, unsigned bpp)
{
	if (buffer)
	{
		if (buffer->bitmap_dc && buffer->bitmap)
		{
			::SelectObject (buffer->bitmap_dc, buffer->bitmap_old);
			::DeleteObject (buffer->bitmap);
			
			buffer->bitmap = 0;
			buffer->bitmap = buffer->pixmap.create_dib_section (buffer->bitmap_dc, dx, dy, (agg::org_e) bpp, 0xff);
			
			buffer->bitmap_old = ::SelectObject (buffer->bitmap_dc, buffer->bitmap);
		}
		else
		{
			buffer->pixmap.create (dx, dy, (agg::org_e) bpp, 0xff);
		}
		
		buffer->buffer.attach (buffer->pixmap.buf (), buffer->pixmap.width (), buffer->pixmap.height (), buffer->pixmap.stride ());
		buffer->renderer->ren_base.reset_clipping (true);
		buffer->renderer_pre->ren_base_pre.reset_clipping (true);
	}
}

void AggBufferDrawGlyphs(AggBuffer* buffer, void* hfont, int x, int y, unsigned short* glyphs, int* dx_array, unsigned int count, unsigned int color)
{
	if (buffer && buffer->bitmap_dc && buffer->bitmap && hfont)
	{
		HGDIOBJ old_hfont = ::SelectObject (buffer->bitmap_dc, (HFONT) hfont);
		
		::SetBkMode (buffer->bitmap_dc, TRANSPARENT);
		::SetTextColor (buffer->bitmap_dc, color);
		::ExtTextOut (buffer->bitmap_dc, x, y, ETO_GLYPH_INDEX, 0, reinterpret_cast<LPCTSTR> (glyphs), count, dx_array);
		::SelectObject (buffer->bitmap_dc, old_hfont);
	}
}

void AggBufferPaint(AggBuffer* buffer, void* hdc, int x1, int y1, int x2, int y2)
{
	if (buffer)
	{
		buffer->pixmap.draw ((HDC) hdc);
	}
}

void AggBufferPaintOffset(AggBuffer* buffer, void* hdc, int ox, int oy, int x1, int y1, int x2, int y2)
{
	if (buffer)
	{
		buffer->pixmap.draw ((HDC) hdc, ox, oy);
	}
}

void AggBufferBlendOffset(AggBuffer* buffer, void* hdc, int ox, int oy, int x1, int y1, int x2, int y2)
{
	if (buffer)
	{
		buffer->pixmap.blend ((HDC) hdc, ox, oy);
	}
}

void AggBufferClear(AggBuffer* buffer)
{
	if (buffer)
	{
#if 1
		buffer->pixmap.clear (0x00);
#else
		int               long_count = buffer->pixmap.height () * buffer->pixmap.stride () / 4;
		unsigned __int32* memory     = (unsigned __int32*) buffer->pixmap.buf ();
		
		while (long_count--)
		{
			*memory++ = 0x01000000;
		}
#endif
	}
}

void AggBufferGetMemoryLayout(AggBuffer* buffer, int & dx, int & dy, int & stride, void*& memory)
{
	if (buffer)
	{
		dx = buffer->pixmap.width ();
		dy = buffer->pixmap.height ();
		stride = buffer->pixmap.stride ();
		memory = buffer->pixmap.buf ();
	}
	else
	{
		dx = 0;
		dy = 0;
		stride = 0;
		memory = 0;
	}
}

void* AggBufferGetMemoryBitmapHandle(AggBuffer* buffer)
{
	if (buffer)
	{
		return buffer->bitmap;
	}
	
	return 0;
}

void AggBufferClearRect(AggBuffer* buffer, int x1, int y1, int x2, int y2)
{
	if (buffer)
	{
		unsigned char* ptr = buffer->pixmap.buf ();
		
		int dx = buffer->pixmap.width ();
		int dy = buffer->pixmap.height ();
		
		if (x1 < 0)  x1 = 0;
		if (y1 < 0)  y1 = 0;
		if (x2 > dx) x2 = dx;
		if (y2 > dy) y2 = dy;
		
		if ( (x1 < x2)
		  && (y1 < y2)
		  && (ptr) )
		{
			int stride = buffer->pixmap.stride ();
			int num = (x2 - x1) * 4;
			
			for (int y = y1; y < y2; y++)
			{
				unsigned char* bits = ptr + y * stride + x1 * 4;
				memset (bits, 0, num);
			}
		}
	}
}

void AggBufferDelete(AggBuffer* buffer)
{
	if (buffer->bitmap_dc && buffer->bitmap)
	{
		::SelectObject (buffer->bitmap_dc, buffer->bitmap_old);
		::DeleteObject (buffer->bitmap);
		::DeleteDC (buffer->bitmap_dc);
		
		buffer->bitmap_dc  = 0;
		buffer->bitmap     = 0;
		buffer->bitmap_old = 0;
	}
	
	delete buffer->renderer;
	delete buffer->renderer_pre;
	delete buffer;
}


void AggBufferInfiniteClipping(AggBuffer* buffer)
{
	buffer->renderer->ren_base.reset_clipping(true);
	buffer->renderer_pre->ren_base_pre.reset_clipping(true);
}

void AggBufferEmptyClipping(AggBuffer* buffer)
{
	buffer->renderer->ren_base.reset_clipping(false);
	buffer->renderer_pre->ren_base_pre.reset_clipping(false);
}

void AggBufferAddClipBox(AggBuffer* buffer, int x1, int y1, int x2, int y2)
{
	buffer->renderer->ren_base.add_clip_box (x1, y1, x2, y2);
	buffer->renderer_pre->ren_base_pre.add_clip_box (x1, y1, x2, y2);
}

void AggBufferBltBuffer(AggBuffer* buffer, int xd, int yd, AggBuffer* source, int xs, int ys, int dx, int dy)
{
	if (buffer && source)
	{
		unsigned char* src_pixels = source->pixmap.buf ();
		unsigned char* dst_pixels = buffer->pixmap.buf ();
		
		int src_byte_width = source->pixmap.stride ();
		int dst_byte_width = buffer->pixmap.stride ();
		
		int x1 = xd;
		int y1 = yd;
		int x2 = xd + dx;
		int y2 = yd + dy;
		
		int x3 = xs;
		int y3 = ys;
		int x4 = xs + dx;
		int y4 = ys + dy;
		
		int d_dx = buffer->pixmap.width ();
		int d_dy = buffer->pixmap.height ();
		int s_dx = source->pixmap.width ();
		int s_dy = source->pixmap.height ();
		
		if (x1 < 0)
		{
			src_pixels -= x1 * 4;
			x3 -= x1;			//	prend plus à droite dans la source pour compenser
			x1  = 0;
		}
		if (x2 > d_dx)
		{
			x2 = d_dx;
		}
		if (y1 < 0)
		{
			src_pixels -= y1 * src_byte_width;
			y3 -= y1;			//	prend plus haut dans la source pour compenser
			y1  = 0;
		}
		if (y2 > d_dy)
		{
			y2 = d_dy;
		}
		
		if (x3 < 0)
		{
			dst_pixels -= x3 * 4;
			x1 -= x3;			//	place plus à droite dans la destination pour compenser
			x3  = 0;
		}
		if (x4 > s_dx)
		{
			x4 = s_dx;
		}
		if (y3 < 0)
		{
			dst_pixels -= y3 * dst_byte_width;
			y1 -= y3;			//	place plus haut dans la destination pour compenser
			y3  = 0;
		}
		if (y4 > s_dy)
		{
			y4 = s_dy;
		}
		
		d_dx = x2 - x1;
		d_dy = y2 - y1;
		s_dx = x4 - x3;
		s_dy = y4 - y3;
		
		dx = d_dx < s_dx ? d_dx : s_dx;
		dy = d_dy < s_dy ? d_dy : s_dy;
		
		if (dx < 1) return;
		if (dy < 1) return;
		
		dst_pixels += x1 * 4;
		dst_pixels += y1 * dst_byte_width;
		
		src_pixels += x3 * 4;
		src_pixels += y3 * src_byte_width;
		
		IppiSize roi_size;
		
		roi_size.width  = dx;
		roi_size.height = dy;
		
		ippiCopy_8u_C4R (src_pixels, src_byte_width, dst_pixels, dst_byte_width, roi_size);
	}
}

void AggBufferComposeBuffer(AggBuffer* buffer, int xd, int yd, AggBuffer* source, int xs, int ys, int dx, int dy)
{
	if (buffer && source)
	{
		unsigned char* src_pixels = source->pixmap.buf ();
		unsigned char* dst_pixels = buffer->pixmap.buf ();
		
		int src_byte_width = source->pixmap.stride ();
		int dst_byte_width = buffer->pixmap.stride ();
		
		int x1 = xd;
		int y1 = yd;
		int x2 = xd + dx;
		int y2 = yd + dy;
		
		int x3 = xs;
		int y3 = ys;
		int x4 = xs + dx;
		int y4 = ys + dy;
		
		int d_dx = buffer->pixmap.width ();
		int d_dy = buffer->pixmap.height ();
		int s_dx = source->pixmap.width ();
		int s_dy = source->pixmap.height ();
		
		if (x1 < 0)
		{
			src_pixels -= x1 * 4;
			x3 -= x1;			//	prend plus à droite dans la source pour compenser
			x1  = 0;
		}
		if (x2 > d_dx)
		{
			x2 = d_dx;
		}
		if (y1 < 0)
		{
			src_pixels -= y1 * src_byte_width;
			y3 -= y1;			//	prend plus haut dans la source pour compenser
			y1  = 0;
		}
		if (y2 > d_dy)
		{
			y2 = d_dy;
		}
		
		if (x3 < 0)
		{
			dst_pixels -= x3 * 4;
			x1 -= x3;			//	place plus à droite dans la destination pour compenser
			x3  = 0;
		}
		if (x4 > s_dx)
		{
			x4 = s_dx;
		}
		if (y3 < 0)
		{
			dst_pixels -= y3 * dst_byte_width;
			y1 -= y3;			//	place plus haut dans la destination pour compenser
			y3  = 0;
		}
		if (y4 > s_dy)
		{
			y4 = s_dy;
		}
		
		d_dx = x2 - x1;
		d_dy = y2 - y1;
		s_dx = x4 - x3;
		s_dy = y4 - y3;
		
		dx = d_dx < s_dx ? d_dx : s_dx;
		dy = d_dy < s_dy ? d_dy : s_dy;
		
		if (dx < 1) return;
		if (dy < 1) return;
		
		dst_pixels += x1 * 4;
		dst_pixels += y1 * dst_byte_width;
		
		src_pixels += x3 * 4;
		src_pixels += y3 * src_byte_width;
		
		IppiSize roi_size;
		
		roi_size.width  = dx;
		roi_size.height = dy;
		
		ippiAlphaComp_8u_AC4R (src_pixels, src_byte_width, dst_pixels, dst_byte_width, dst_pixels, dst_byte_width, roi_size, ippAlphaOverPremul);
	}
}
