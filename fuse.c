#include <fuse.h>
#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif
/** Function to add an entry in a readdir() operation
 *
 * @param buf the buffer passed to the readdir() operation
 * @param name the file name of the directory entry
 * @param stbuf file attributes, can be NULL
 * @param off offset of the next entry or zero
 * @return 1 if buffer is full, zero otherwise
 */
typedef int (*fuse_fill_dir_t) (void *buf, const char *name,
				const struct stat *stbuf, off_t off);

/** Get file attributes.
	 *
	 * Similar to stat().  The 'st_dev' and 'st_blksize' fields are
	 * ignored.	 The 'st_ino' field is ignored except if the 'use_ino'
	 * mount option is given.
	 */
int ft_getattr (const char *path, struct stat *s)
{
    return 0;
}
/** Read directory
	 *
	 * This supersedes the old getdir() interface.  New applications
	 * should use this.
	 *
	 * The filesystem may choose between two modes of operation:
	 *
	 * 1) The readdir implementation ignores the offset parameter, and
	 * passes zero to the filler function's offset.  The filler
	 * function will not return '1' (unless an error happens), so the
	 * whole directory is read in a single readdir operation.  This
	 * works just like the old getdir() method.
	 *
	 * 2) The readdir implementation keeps track of the offsets of the
	 * directory entries.  It uses the offset parameter and always
	 * passes non-zero offset to the filler function.  When the buffer
	 * is full (or an error happens) the filler function will return
	 * '1'.
	 *
	 * Introduced in version 2.3
	 */
int ft_readdir (const char *path, void *cookie, fuse_fill_dir_t handler, off_t offset,
			struct fuse_file_info *fi)
{
    return 0;
}


static struct fuse_operations myOperations = {
	.getattr = ft_getattr,
	.readdir = ft_readdir
};

int main(int argc, char* argv[]){
    return fuse_main(argc, argv, &myOperations, 0);
}