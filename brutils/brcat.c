/* http://sourceforge.net/projects/excat/develop
 * http://blog.fraggod.net/2010/12/zcat-bzcat-lzcat-xzcat-Arrrgh-Autodetection-rocks
 * http://code.google.com/p/libarchive/wiki/LibarchiveFormats
 * Mike Kazantsev 
 * License: BSD
 *
 *
 * Filter Support
 * gzip 
 * bzip2
 * compress
 * uudecode
 */

#include <archive.h>
#include <archive_entry.h>
#include <stdio.h>
#include <stdlib.h>

const int BS = 16384;

int main(int argc, const char **argv) {
	if (argc > 2) {
		fprintf(stderr, "Usage: %s [file]\n", argv[0]);
		exit(1); }

	struct archive *a = archive_read_new();
	archive_read_support_compression_all(a);
	archive_read_support_format_raw(a);

	int err;
	if (argc == 2) err = archive_read_open_filename(a, argv[1], BS);
	else err = archive_read_open_fd(a, 0, BS);
	if (err != ARCHIVE_OK) {
		fprintf(stderr, "Broken archive (1)\n");
		exit(1); }

	struct archive_entry *ae;
	err = archive_read_next_header(a, &ae);
	if (err != ARCHIVE_OK) {
		fprintf(stderr, "Broken archive (2)\n");
		exit(1); }

	(void) archive_read_data_into_fd(a, 1);

	archive_read_finish(a);
	exit(0);
}

