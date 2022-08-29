#ifndef RWFILE_H
#define RWFILE_H

/// @brief Gets file size in bytes
///
/// @param[in] filename name of file
///
/// @return size of file in bytes on success,
/// -1 on error
off_t get_file_size(const char *filename);

enum retcodes_read_file {                   ///< enumeration of return codes of read_file()
                        ERR_FILE      = 0, ///< file openning error code
                        };

/// @brief Reads data from file into dynamic memory buffer
///
/// @param[in] filename name of file which read from
/// @param[out] buffer buffer where text store to
/// @param[out] nSymbols number of symbols to read
///
/// @return number of bytes read on success,
/// 0 on file openning error
///
/// @note this function does not distinguish empty file and error
size_t read_file(const char *filename, char *buffer, size_t nSymbols);

#endif /* RWFILE_H */
