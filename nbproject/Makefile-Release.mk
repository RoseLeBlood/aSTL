#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Base-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/PLATFORM.o \
	${OBJECTDIR}/src/application.o \
	${OBJECTDIR}/src/asstl.o \
	${OBJECTDIR}/src/exception.o \
	${OBJECTDIR}/src/filestream.o \
	${OBJECTDIR}/src/intrusive_list.o \
	${OBJECTDIR}/src/intrusive_slist.o \
	${OBJECTDIR}/src/iostream.o \
	${OBJECTDIR}/src/list.o \
	${OBJECTDIR}/src/math/math.o \
	${OBJECTDIR}/src/mutex.o \
	${OBJECTDIR}/src/network/address.o \
	${OBJECTDIR}/src/network/physicaladdress.o \
	${OBJECTDIR}/src/new.o \
	${OBJECTDIR}/src/slist.o \
	${OBJECTDIR}/src/spinlock.o \
	${OBJECTDIR}/src/split.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libastl.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libastl.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libastl.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libastl.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libastl.a

${OBJECTDIR}/src/PLATFORM.o: src/PLATFORM.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/PLATFORM.o src/PLATFORM.cpp

${OBJECTDIR}/src/application.o: src/application.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/application.o src/application.cpp

${OBJECTDIR}/src/asstl.o: src/asstl.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/asstl.o src/asstl.cpp

${OBJECTDIR}/src/exception.o: src/exception.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/exception.o src/exception.cpp

${OBJECTDIR}/src/filestream.o: src/filestream.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/filestream.o src/filestream.cpp

${OBJECTDIR}/src/intrusive_list.o: src/intrusive_list.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/intrusive_list.o src/intrusive_list.cpp

${OBJECTDIR}/src/intrusive_slist.o: src/intrusive_slist.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/intrusive_slist.o src/intrusive_slist.cpp

${OBJECTDIR}/src/iostream.o: src/iostream.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/iostream.o src/iostream.cpp

${OBJECTDIR}/src/list.o: src/list.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/list.o src/list.cpp

${OBJECTDIR}/src/math/math.o: src/math/math.cpp
	${MKDIR} -p ${OBJECTDIR}/src/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/math/math.o src/math/math.cpp

${OBJECTDIR}/src/mutex.o: src/mutex.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mutex.o src/mutex.cpp

${OBJECTDIR}/src/network/address.o: src/network/address.cpp
	${MKDIR} -p ${OBJECTDIR}/src/network
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/network/address.o src/network/address.cpp

${OBJECTDIR}/src/network/physicaladdress.o: src/network/physicaladdress.cpp
	${MKDIR} -p ${OBJECTDIR}/src/network
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/network/physicaladdress.o src/network/physicaladdress.cpp

${OBJECTDIR}/src/new.o: src/new.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/new.o src/new.cpp

${OBJECTDIR}/src/slist.o: src/slist.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/slist.o src/slist.cpp

${OBJECTDIR}/src/spinlock.o: src/spinlock.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/spinlock.o src/spinlock.cpp

${OBJECTDIR}/src/split.o: src/split.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/split.o src/split.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
