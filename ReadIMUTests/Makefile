# Compiler, tools and options
RTIMULIBPATH  = ../../RTIMULib

CC    			= gcc
CXX   			= g++
DEFINES     =
CFLAGS			= -pipe -O2 -Wall -W $(DEFINES)
CXXFLAGS    = -pipe -O2 -Wall -W $(DEFINES)
INCPATH     = -I. -I$(RTIMULIBPATH)
LINK  			= g++
LFLAGS			= -Wl,-O1
LIBS  			= -L/usr/lib/arm-linux-gnueabihf
COPY  			= cp -f
COPY_FILE   = $(COPY)
COPY_DIR    = $(COPY) -r
STRIP 			= strip
INSTALL_FILE  	= install -m 644 -p
INSTALL_DIR   	= $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      	= rm -f
SYMLINK       	= ln -f -s
DEL_DIR       	= rmdir
MOVE  					= mv -f
CHK_DIR_EXISTS	= test -d
MKDIR						= mkdir -p

# Output directory
OBJECTS_DIR   = objects/

# Files
DEPS    = $(RTIMULIBPATH)/RTMath.h \
    $(RTIMULIBPATH)/RTIMULib.h \
    $(RTIMULIBPATH)/RTIMULibDefs.h \
    $(RTIMULIBPATH)/RTIMUHal.h \
    $(RTIMULIBPATH)/RTFusion.h \
    $(RTIMULIBPATH)/RTFusionKalman4.h \
    $(RTIMULIBPATH)/RTFusionRTQF.h \
    $(RTIMULIBPATH)/RTIMUSettings.h \
    $(RTIMULIBPATH)/RTIMUAccelCal.h \
    $(RTIMULIBPATH)/RTIMUMagCal.h \
    $(RTIMULIBPATH)/RTIMUCalDefs.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMU.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUNull.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUMPU9150.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUMPU9250.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUGD20HM303D.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUGD20M303DLHC.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUGD20HM303DLHC.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMULSM9DS0.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMULSM9DS1.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUBMX055.h \
    $(RTIMULIBPATH)/IMUDrivers/RTIMUBNO055.h \
    $(RTIMULIBPATH)/IMUDrivers/RTPressure.h \
    $(RTIMULIBPATH)/IMUDrivers/RTPressureBMP180.h \
    $(RTIMULIBPATH)/IMUDrivers/RTPressureLPS25H.h \
    $(RTIMULIBPATH)/IMUDrivers/RTPressureMS5611.h \
    $(RTIMULIBPATH)/IMUDrivers/RTPressureMS5637.h

OBJECTS = objects/CommandLineIMU.o \
    objects/RTMath.o \
    objects/RTIMUHal.o \
    objects/RTFusion.o \
    objects/RTFusionKalman4.o \
    objects/RTFusionRTQF.o \
    objects/RTIMUSettings.o \
    objects/RTIMUAccelCal.o \
    objects/RTIMUMagCal.o \
    objects/RTIMU.o \
    objects/RTIMUNull.o \
    objects/RTIMUMPU9150.o \
    objects/RTIMUMPU9250.o \
    objects/RTIMUGD20HM303D.o \
    objects/RTIMUGD20M303DLHC.o \
    objects/RTIMUGD20HM303DLHC.o \
    objects/RTIMULSM9DS0.o \
    objects/RTIMULSM9DS1.o \
    objects/RTIMUBMX055.o \
    objects/RTIMUBNO055.o \
    objects/RTPressure.o \
    objects/RTPressureBMP180.o \
    objects/RTPressureLPS25H.o \
    objects/RTPressureMS5611.o \
    objects/RTPressureMS5637.o

MAKE_TARGET	= CommandLineIMU
DESTDIR		= Output/
TARGET		= Output/$(MAKE_TARGET)

# Build rules
$(TARGET): $(OBJECTS)
	@$(CHK_DIR_EXISTS) Output/ || $(MKDIR) Output/
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core

# Compile
$(OBJECTS_DIR)%.o : $(RTIMULIBPATH)/%.cpp $(DEPS)
	@$(CHK_DIR_EXISTS) objects/ || $(MKDIR) objects/
	$(CXX) -c -o $@ $< $(CFLAGS) $(INCPATH)

$(OBJECTS_DIR)%.o : $(RTIMULIBPATH)/IMUDrivers/%.cpp $(DEPS)
	@$(CHK_DIR_EXISTS) objects/ || $(MKDIR) objects/
	$(CXX) -c -o $@ $< $(CFLAGS) $(INCPATH)

$(OBJECTS_DIR)CommandLineIMU.o : CommandLineIMU.cpp $(DEPS)
	@$(CHK_DIR_EXISTS) objects/ || $(MKDIR) objects/
	$(CXX) -c -o $@ CommandLineIMU.cpp $(CFLAGS) $(INCPATH)

# Install
install_target: FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/bin/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/bin/
	-$(INSTALL_PROGRAM) "Output/$(MAKE_TARGET)" "$(INSTALL_ROOT)/usr/local/bin/$(MAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/usr/local/bin/$(MAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/usr/local/bin/$(MAKE_TARGET)"

install:  install_target  FORCE
uninstall: uninstall_target   FORCE
FORCE:

