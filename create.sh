#!/bin/sh
# usage: create.sh localpath cell volume

mkdir -p $1/.afssync
sqlite3 $1/.afssync/db.sqlite <<EOF
create table if not exists config (seq integer primary key, cell text, volume text);
create table if not exists files (seq integer primary key, vnode integer, uniq integer, filetype integer, mode integer, dataversion integer, path text, localmodtime integer, length integer, checksum text, deleted integer);
insert into config (seq, cell, volume) values (1, "$2", "$3");
EOF

mkdir -p $1/.afssync/fetched
mkdir -p $1/.afssync/trash
