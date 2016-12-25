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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/10693597/wostream.o \
	${OBJECTDIR}/PLATFORM.o \
	${OBJECTDIR}/application.o \
	${OBJECTDIR}/asstl.o \
	${OBJECTDIR}/filestream.o \
	${OBJECTDIR}/intrusive_list.o \
	${OBJECTDIR}/intrusive_slist.o \
	${OBJECTDIR}/iostream.o \
	${OBJECTDIR}/list.o \
	${OBJECTDIR}/math/math.o \
	${OBJECTDIR}/mutex.o \
	${OBJECTDIR}/new.o \
	${OBJECTDIR}/slist.o \
	${OBJECTDIR}/spinlock.o \
	${OBJECTDIR}/split.o


# C Compiler Flags
CFLAGS=-m32

# CC Compiler Flags
CCFLAGS=-m32 -msse2 -msse3 -mfpmath=sse -fpermissive -march=native --with-mfpmath=sse
CXXFLAGS=-m32 -msse2 -msse3 -mfpmath=sse -fpermissive -march=native --with-mfpmath=sse

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libasstl.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libasstl.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libasstl.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libasstl.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libasstl.a

${OBJECTDIR}/_ext/10693597/wostream.o: /D/annas/Documents/asstl/asstl/wostream.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/10693597
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/10693597/wostream.o /D/annas/Documents/asstl/asstl/wostream.cpp

${OBJECTDIR}/PLATFORM.o: PLATFORM.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PLATFORM.o PLATFORM.cpp

${OBJECTDIR}/application.o: application.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/application.o application.cpp

${OBJECTDIR}/asstl.o: asstl.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/asstl.o asstl.cpp

${OBJECTDIR}/filestream.o: filestream.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filestream.o filestream.cpp

${OBJECTDIR}/intrusive_list.o: intrusive_list.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/intrusive_list.o intrusive_list.cpp

${OBJECTDIR}/intrusive_slist.o: intrusive_slist.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/intrusive_slist.o intrusive_slist.cpp

${OBJECTDIR}/iostream.o: iostream.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iostream.o iostream.cpp

${OBJECTDIR}/list.o: list.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/list.o list.cpp

${OBJECTDIR}/math/math.o: math/math.cpp
	${MKDIR} -p ${OBJECTDIR}/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/math/math.o math/math.cpp

${OBJECTDIR}/mutex.o: mutex.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mutex.o mutex.cpp

${OBJECTDIR}/new.o: new.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/new.o new.cpp

${OBJECTDIR}/slist.o: slist.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/slist.o slist.cpp

${OBJECTDIR}/spinlock.o: spinlock.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/spinlock.o spinlock.cpp

${OBJECTDIR}/split.o: split.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/split.o split.cpp

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