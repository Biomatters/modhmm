

SET (GENERAL_H_FILES "funcs.h;structs.h")
SET (GENERAL_C_FILES "readhmm.c;readhmm_multialpha.c;std_funcs.c;savehmm.c;savehmm_multialpha.c;debug_funcs.c;readseqs_multialpha.c")
SET (SCORING_C_FILES "core_algorithms_multialpha.c;std_calculation_funcs.c")

add_executable (modhmms cmdline_hmmsearch.h ${GENERAL_H_FILES} cmdline_hmmsearch.c hmmsearch.c ${GENERAL_C_FILES} ${SCORING_C_FILES} training_algorithms_multialpha.c)
add_executable (modhmmt cmdline_hmmtrain.h  ${GENERAL_H_FILES} cmdline_hmmtrain.c hmmtrain.c ${GENERAL_C_FILES} ${SCORING_C_FILES} training_algorithms_multialpha.c)
add_executable (modseqalign cmdline_modseqalign.h ${GENERAL_H_FILES} cmdline_modseqalign.c modseqalign.c ${GENERAL_C_FILES} ${SCORING_C_FILES})
add_executable (add_alphabet cmdline_add_alphabet.h ${GENERAL_H_FILES} cmdline_add_alphabet.c add_alphabet.c ${GENERAL_C_FILES})


target_link_libraries (modhmms m)
target_link_libraries (modhmmt m)
target_link_libraries (modseqalign m)
target_link_libraries (add_alphabet m)

install(TARGETS modhmms modhmmt modseqalign add_alphabet DESTINATION bin)

