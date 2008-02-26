/* cmdline_hmmtrain.h */

/* File autogenerated by gengetopt version 2.12.2  */

#ifndef CMDLINE_HMMTRAIN_H
#define CMDLINE_HMMTRAIN_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
#define CMDLINE_PARSER_PACKAGE "modhmmt"
#endif

#ifndef CMDLINE_PARSER_VERSION
#define CMDLINE_PARSER_VERSION "0.92"
#endif

struct gengetopt_args_info
{
  char * hmminfile_arg;	/* modelfile (in .hmg format).  */
  char * seqnamefile_arg;	/* sequence namefile (for sequences in fasta, smod, msamod or prfmod format).  */
  char * seqformat_arg;	/* format of input sequences (fa=fasta, s=smod, msa=msamod, prf=prfmod).  */
  char * outfile_arg;	/* model outfile.  */
  char * freqfile_arg;	/* background frequency file.  */
  char * smxfile_arg;	/* substitution matrix file.  */
  char * replfile_arg;	/* replacement letter file.  */
  char * alg_arg;	/* training algorithm (cml=conditional maximum likelihood, bw=baum-welch (default), disc=discriminative training).  */
  char * negseqnamefile_arg;	/* sequence namefile for negative training sequences (for sequences in fasta, smod, msamod
or prfmod format).  */
  char * optalpha_arg;	/* alphabet to optimize (parameters for transitions and all other alphabets will not be changed.  */
  char * msascoring_arg;	/* scoring method for alignment and profile data options = DP/DPPI/GM/GMR/DPPI/PI/PIS default=GM.  */
  char * usecolumns_arg;	/* specify which columns to use for alignment input data, options = all/nr, where all means use all columns
and nr specifies a sequence in the alignment and the columns where this sequence have non-gap symbls are used
default = all.  */
  int nolabels_flag;	/* do not use labels even though the input sequences are labeled (default=off).  */
  int noprior_flag;	/* do not use priors when training even though the the model file has prior files specified (default=off).  */
  int tpcounts_flag;	/* use pseudocounts for transition parameter updates (default=off).  */
  int epcounts_flag;	/* use pseudocounts for emission parameter updates (default=off).  */
  int transonly_flag;	/* only update transition parameters (default=off).  */
  int emissonly_flag;	/* only update emission parameters (default=off).  */
  int verbose_flag;	/* print some information about what is going on (default=off).  */

  int help_given ;	/* Whether help was given.  */
  int version_given ;	/* Whether version was given.  */
  int hmminfile_given ;	/* Whether hmminfile was given.  */
  int seqnamefile_given ;	/* Whether seqnamefile was given.  */
  int seqformat_given ;	/* Whether seqformat was given.  */
  int outfile_given ;	/* Whether outfile was given.  */
  int freqfile_given ;	/* Whether freqfile was given.  */
  int smxfile_given ;	/* Whether smxfile was given.  */
  int replfile_given ;	/* Whether replfile was given.  */
  int alg_given ;	/* Whether alg was given.  */
  int negseqnamefile_given ;	/* Whether negseqnamefile was given.  */
  int optalpha_given ;	/* Whether optalpha was given.  */
  int msascoring_given ;	/* Whether msascoring was given.  */
  int usecolumns_given ;	/* Whether usecolumns was given.  */
  int nolabels_given ;	/* Whether nolabels was given.  */
  int noprior_given ;	/* Whether noprior was given.  */
  int tpcounts_given ;	/* Whether tpcounts was given.  */
  int epcounts_given ;	/* Whether epcounts was given.  */
  int transonly_given ;	/* Whether transonly was given.  */
  int emissonly_given ;	/* Whether emissonly was given.  */
  int verbose_given ;	/* Whether verbose was given.  */

} ;

int cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info);
int cmdline_parser2 (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required);

void cmdline_parser_print_help(void);
void cmdline_parser_print_version(void);

void cmdline_parser_init (struct gengetopt_args_info *args_info);
void cmdline_parser_free (struct gengetopt_args_info *args_info);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_HMMTRAIN_H */
