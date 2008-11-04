FIND_PROGRAM(GENGETOPT gengetopt)
IF(NOT GENGETOPT)
 SET(GENGETOPTDEP "${CMAKE_CURRENT_BINARY_DIR}/external/install/bin/gengetopt"  )
IF(WIN32)
 SET(GENGETOPTDEP "${GENGETOPTDEP}.exe"  )
ENDIF(WIN32)
 SET(GENGETOPT "${GENGETOPTDEP}" )
ENDIF(NOT GENGETOPT)

IF(STATIC)
 SET(LIBXML2_INCLUDE_DIR  "${CMAKE_CURRENT_BINARY_DIR}/external/install/include/libxml2" )
 SET(LIBXML2_LIBRARIES  "${CMAKE_CURRENT_BINARY_DIR}/external/install/lib/libxml2.a" )

# The next line seems to be need for macosx
 SET(ZLIB_LIBRARY "${CMAKE_CURRENT_BINARY_DIR}/external/install/lib/libz.a" )
ENDIF(STATIC)

SET(GENGETOPT_VERSION 2.22 )
SET(LIBXML2_VERSION 2.7.2 )
SET(ZLIB_VERSION 1.2.3 )

SET(DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/external/downloads" INTERNAL )
SET(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/build INTERNAL )
SET(INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/install INTERNAL )

file( MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/external/download )
file( MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/external/build )
file( MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/external/install )
file( MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gengetopt )

ADD_CUSTOM_COMMAND( OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/fastphylo-${PACKAGE_VERSION}-win32.exe" COMMAND makensis "${CMAKE_CURRENT_BINARY_DIR}/script.nsi" DEPENDS fastdist fnj )
ADD_CUSTOM_TARGET( win32installer DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/fastphylo-${PACKAGE_VERSION}-win32.exe" )
ADD_CUSTOM_COMMAND( OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/external/download/gengetopt-${GENGETOPT_VERSION}.tar.gz" COMMAND  wget --directory-prefix=external/download "ftp://ftp.gnu.org/gnu/gengetopt/gengetopt-${GENGETOPT_VERSION}.tar.gz" )
ADD_CUSTOM_COMMAND( OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/external/download/libxml2-${LIBXML2_VERSION}.tar.gz" COMMAND  wget --directory-prefix=external/download  "ftp://xmlsoft.org/libxml2/libxml2-${LIBXML2_VERSION}.tar.gz" )
ADD_CUSTOM_COMMAND( OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/external/download/zlib-${ZLIB_VERSION}.tar.gz" COMMAND  wget --directory-prefix=external/download  "http://www.gzip.org/zlib/zlib-${ZLIB_VERSION}.tar.gz" )
ADD_CUSTOM_COMMAND( OUTPUT "${GENGETOPTDEP}" COMMAND sh "${CMAKE_CURRENT_SOURCE_DIR}/build_gengetopt.sh" ${GENGETOPT_VERSION} "${CMAKE_CURRENT_BINARY_DIR}/external/install"  DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/external/download/gengetopt-${GENGETOPT_VERSION}.tar.gz" WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/external/build" )
ADD_CUSTOM_COMMAND( OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/external/install/lib/libxml2.a" "${CMAKE_CURRENT_BINARY_DIR}/external/install/include/libxml2/libxml/xmlreader.h" COMMAND sh "${CMAKE_CURRENT_SOURCE_DIR}/build_libxml2.sh" ${LIBXML2_VERSION} "${CMAKE_CURRENT_BINARY_DIR}/external/install"  DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/external/download/libxml2-${LIBXML2_VERSION}.tar.gz" "${CMAKE_CURRENT_BINARY_DIR}/external/install/lib/libz.a"  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/external/build" )
ADD_CUSTOM_COMMAND( OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/external/install/lib/libz.a" COMMAND sh "${CMAKE_CURRENT_SOURCE_DIR}/build_zlib.sh" ${ZLIB_VERSION} "${CMAKE_CURRENT_BINARY_DIR}/external/install"  DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/external/download/zlib-${ZLIB_VERSION}.tar.gz"  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/external/build" )

SET(PROGRAMS modhmms modhmmt modseqalign add_alphabet) 

FOREACH(i ${PROGRAMS} )
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/gengetopt/cmdline_${i}.ggo.cmake ${CMAKE_CURRENT_BINARY_DIR}/gengetopt/cmdline_${i}.ggo)
  add_custom_command(OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/cmdline_${i}.c   ${CMAKE_CURRENT_BINARY_DIR}/cmdline_${i}.h 
                     COMMAND ${GENGETOPT} -i  ${CMAKE_CURRENT_BINARY_DIR}/gengetopt/cmdline_${i}.ggo --file-name=cmdline_${i}  --output-dir=${CMAKE_CURRENT_BINARY_DIR}
                     DEPENDS   ${CMAKE_CURRENT_BINARY_DIR}/gengetopt/cmdline_${i}.ggo  ${GENGETOPTDEP}
                     VERBATIM)
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/cmdline_${i}.c PROPERTIES GENERATED true)
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/cmdline_${i}.h PROPERTIES GENERATED true)
ENDFOREACH(i)

IF(WITH_LIBXML)
  FIND_PACKAGE(LibXml2)
ENDIF(WITH_LIBXML)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/script.nsi.cmake ${CMAKE_CURRENT_BINARY_DIR}/script.nsi)

INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/)

IF(STATIC AND WITH_LIBXML)
 set( LIBXML_EXTRA_COMPILE_FLAGS " -DLIBXML_STATIC " )
ENDIF(STATIC AND WITH_LIBXML)

IF(WITH_LIBXML)
 IF(STATIC)
#  SET(FASTDIST_XML_SRCS programs/fastdist/XmlInputStream.cpp  "${CMAKE_CURRENT_BINARY_DIR}/external/install/include/libxml2/libxml/xmlreader.h" )
 ELSE(STATIC)
#  SET(FASTDIST_XML_SRCS programs/fastdist/XmlInputStream.cpp )
 ENDIF(STATIC)
ENDIF(WITH_LIBXML)


SET(FNJ_SRCS programs/fnj/main.cpp
programs/fnj/DataInputStream.cpp
programs/fnj/DataOutputStream.cpp
programs/fnj/XmlOutputStream.cpp
${CMAKE_CURRENT_BINARY_DIR}/programs/fnj/gengetopt/fnj_gengetopt.c 
)

IF(WITH_LIBXML)
 IF(STATIC)
  SET(FNJ_XML_SRCS programs/fnj/XmlInputStream.cpp  "${CMAKE_CURRENT_BINARY_DIR}/external/install/include/libxml2/libxml/xmlreader.h" )
 ELSE(STATIC)
  SET(FNJ_XML_SRCS programs/fnj/XmlInputStream.cpp )
 ENDIF(STATIC)
ENDIF(WITH_LIBXML)

SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/${LIBXML2_INCLUDE_DIR}/libxml/xmlreader.h PROPERTIES GENERATED TRUE HEADER_FILE_ONLY TRUE )

SET (GENERAL_H_FILES funcs.h
                     structs.h)
SET (GENERAL_C_FILES readhmm.c
                     readhmm_multialpha.c
                     std_funcs.c
                     savehmm.c
                     savehmm_multialpha.c
                     debug_funcs.c
                     readseqs_multialpha.c)
SET (SCORING_C_FILES core_algorithms_multialpha.c
                     std_calculation_funcs.c)

add_executable (modhmms modhmms.c cmdline_modhmms.c ${GENERAL_C_FILES} ${SCORING_C_FILES} training_algorithms_multialpha.c)
add_executable (modhmmt  modhmmt.c modhmmt_cmdline.c ${GENERAL_C_FILES} ${SCORING_C_FILES} training_algorithms_multialpha.c)
add_executable (modseqalign modseqalign.c cmdline_modseqalign.c ${GENERAL_C_FILES} ${SCORING_C_FILES})
add_executable (add_alphabet add_alphabet.c cmdline_add_alphabet.c programs/add_alphabet/main.c ${GENERAL_C_FILES})

FOREACH(i ${PROGRAMS} )
 IF(STATIC)
  set_property(TARGET ${i} PROPERTY LINK_SEARCH_END_STATIC ON )
 ENDIF(STATIC)
# ${LIBXML2_LIBRARIES}  ${ZLIB_LIBRARY}
 target_link_libraries (${i} m)
ENDFOREACH(i)

install(TARGETS ${PROGRAMS} DESTINATION bin)




