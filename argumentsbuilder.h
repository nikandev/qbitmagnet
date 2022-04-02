#ifndef ARGUMENTSBUILDER_H
#define ARGUMENTSBUILDER_H

#include <QString>

//%N: Torrent name
//%L: Category
//%G: Tags (separated by comma)
//%F: Content path (same as root path for multifile torrent)
//%R: Root path (first torrent subdirectory path)
//%D: Save path
//%C: Number of files
//%Z: Torrent size (bytes)
//%T: Current tracker
//%I: Info hash v1
//%J: Info hash v2
//%K: Torrent ID

struct Arguments
{
       bool isNull = true;
       QString TorrentName;
       QString Torrentsize;
       QString Currenttracker;
       QString Infohashv1;
       QString Infohashv2;
};

class ArgumentsBuilder
{
    public:
        static Arguments buildArguments();
};

#endif // ARGUMENTSBUILDER_H
