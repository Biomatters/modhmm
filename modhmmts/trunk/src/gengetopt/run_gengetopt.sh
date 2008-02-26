gengetopt=~/Private/nfsvol/oldNFS/gengetopt/bin/gengetopt

$gengetopt < hmmtrain.ggo --file-name=cmdline_hmmtrain
$gengetopt < hmmsearch.ggo --file-name=cmdline_hmmsearch
$gengetopt < modseqalign.ggo --file-name=cmdline_modseqalign
$gengetopt < add_alphabet.ggo --file-name=cmdline_add_alphabet
cp cmdline* ../
