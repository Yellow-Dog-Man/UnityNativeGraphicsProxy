SRCDIR = ../../source
SRCS = $(SRCDIR)/RenderCallback.cpp \
$(SRCDIR)/OpenGLCoreES.cpp
OBJS = ${SRCS:.cpp=.o}
UNITY_DEFINES = -DSUPPORT_OPENGL_UNIFIED=1 -DUNITY_LINUX=1
CXXFLAGS = $(UNITY_DEFINES) -O3 -fPIC
LDFLAGS = -shared -rdynamic
LIBS =
PLUGIN_SHARED = libNativeGraphics.so
CXX ?= g++

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: shared

clean:
	rm -f $(OBJS) $(PLUGIN_SHARED)

shared: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PLUGIN_SHARED) $(OBJS) $(LIBS)
