include ../Makefile.in.$(shell uname)

CXXFLAGS= $(AGGCXXFLAGS) -I. -I../include -L./

SRC_CXX=\
agg_font_face.cpp \
agg_font_manager.cpp \
agg_font_manager_rec.cpp \
agg_font_opentype.cpp \
agg_font_path_provider.cpp

OBJ=$(SRC_CXX:.cpp=.o)

all:	$(OBJ)
	$(LIB) libaggfont.a $(OBJ) 

clean:
	rm -f *.o *.a
	rm -rf SunWS_cache
	rm -rf ctrl/SunWS_cache

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $*.cpp -o $@

%.o: %.c
	$(C) -c $(CXXFLAGS) $*.c -o $@
