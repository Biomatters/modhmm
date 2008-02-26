/* cmdline_add_alphabet.h */

/* File autogenerated by gengetopt version 2.12.2  */

#ifndef CMDLINE_ADD_ALPHABET_H
#define CMDLINE_ADD_ALPHABET_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
#define CMDLINE_PARSER_PACKAGE "add_alphabet"
#endif

#ifndef CMDLINE_PARSER_VERSION
#define CMDLINE_PARSER_VERSION "0.92"
#endif

struct gengetopt_args_info
{
  char * hmminfile_arg;	/* modelfile (in .hmg format).  */
  char * outfile_arg;	/* model outfile.  */
  char * alphafile_arg;	/* alphabet file.  */
  int verbose_flag;	/* print some information about what is going on (default=off).  */

  int help_given ;	/* Whether help was given.  */
  int version_given ;	/* Whether version was given.  */
  int hmminfile_given ;	/* Whether hmminfile was given.  */
  int outfile_given ;	/* Whether outfile was given.  */
  int alphafile_given ;	/* Whether alphafile was given.  */
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
#endif /* CMDLINE_ADD_ALPHABET_H */
