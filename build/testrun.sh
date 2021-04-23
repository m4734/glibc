#!/bin/bash
builddir=`dirname "$0"`
GCONV_PATH="${builddir}/iconvdata"

usage () {
  echo "usage: $0 [--tool=strace] PROGRAM [ARGUMENTS...]" 2>&1
  echo "       $0 --tool=valgrind PROGRAM [ARGUMENTS...]" 2>&1
  exit 1
}

toolname=default
while test $# -gt 0 ; do
  case "$1" in
    --tool=*)
      toolname="${1:7}"
      shift
      ;;
    --*)
      usage
      ;;
    *)
      break
      ;;
  esac
done

if test $# -eq 0 ; then
  usage
fi

case "$toolname" in
  default)
    exec   env GCONV_PATH="${builddir}"/iconvdata LOCPATH="${builddir}"/localedata LC_ALL=C  "${builddir}"/elf/ld-linux-x86-64.so.2 --library-path "${builddir}":"${builddir}"/math:"${builddir}"/elf:"${builddir}"/dlfcn:"${builddir}"/nss:"${builddir}"/nis:"${builddir}"/rt:"${builddir}"/resolv:"${builddir}"/mathvec:"${builddir}"/support:"${builddir}"/crypt:"${builddir}"/nptl ${1+"$@"}
    ;;
  strace)
    exec strace  -EGCONV_PATH=/home/cgmin/20210402/glibc/build/iconvdata  -ELOCPATH=/home/cgmin/20210402/glibc/build/localedata  -ELC_ALL=C  /home/cgmin/20210402/glibc/build/elf/ld-linux-x86-64.so.2 --library-path /home/cgmin/20210402/glibc/build:/home/cgmin/20210402/glibc/build/math:/home/cgmin/20210402/glibc/build/elf:/home/cgmin/20210402/glibc/build/dlfcn:/home/cgmin/20210402/glibc/build/nss:/home/cgmin/20210402/glibc/build/nis:/home/cgmin/20210402/glibc/build/rt:/home/cgmin/20210402/glibc/build/resolv:/home/cgmin/20210402/glibc/build/mathvec:/home/cgmin/20210402/glibc/build/support:/home/cgmin/20210402/glibc/build/crypt:/home/cgmin/20210402/glibc/build/nptl ${1+"$@"}
    ;;
  valgrind)
    exec env GCONV_PATH=/home/cgmin/20210402/glibc/build/iconvdata LOCPATH=/home/cgmin/20210402/glibc/build/localedata LC_ALL=C valgrind  /home/cgmin/20210402/glibc/build/elf/ld-linux-x86-64.so.2 --library-path /home/cgmin/20210402/glibc/build:/home/cgmin/20210402/glibc/build/math:/home/cgmin/20210402/glibc/build/elf:/home/cgmin/20210402/glibc/build/dlfcn:/home/cgmin/20210402/glibc/build/nss:/home/cgmin/20210402/glibc/build/nis:/home/cgmin/20210402/glibc/build/rt:/home/cgmin/20210402/glibc/build/resolv:/home/cgmin/20210402/glibc/build/mathvec:/home/cgmin/20210402/glibc/build/support:/home/cgmin/20210402/glibc/build/crypt:/home/cgmin/20210402/glibc/build/nptl ${1+"$@"}
    ;;
  container)
    exec env GCONV_PATH=/home/cgmin/20210402/glibc/build/iconvdata LOCPATH=/home/cgmin/20210402/glibc/build/localedata LC_ALL=C  /home/cgmin/20210402/glibc/build/elf/ld-linux-x86-64.so.2 --library-path /home/cgmin/20210402/glibc/build:/home/cgmin/20210402/glibc/build/math:/home/cgmin/20210402/glibc/build/elf:/home/cgmin/20210402/glibc/build/dlfcn:/home/cgmin/20210402/glibc/build/nss:/home/cgmin/20210402/glibc/build/nis:/home/cgmin/20210402/glibc/build/rt:/home/cgmin/20210402/glibc/build/resolv:/home/cgmin/20210402/glibc/build/mathvec:/home/cgmin/20210402/glibc/build/support:/home/cgmin/20210402/glibc/build/crypt:/home/cgmin/20210402/glibc/build/nptl /home/cgmin/20210402/glibc/build/support/test-container env GCONV_PATH=/home/cgmin/20210402/glibc/build/iconvdata LOCPATH=/home/cgmin/20210402/glibc/build/localedata LC_ALL=C  /home/cgmin/20210402/glibc/build/elf/ld-linux-x86-64.so.2 --library-path /home/cgmin/20210402/glibc/build:/home/cgmin/20210402/glibc/build/math:/home/cgmin/20210402/glibc/build/elf:/home/cgmin/20210402/glibc/build/dlfcn:/home/cgmin/20210402/glibc/build/nss:/home/cgmin/20210402/glibc/build/nis:/home/cgmin/20210402/glibc/build/rt:/home/cgmin/20210402/glibc/build/resolv:/home/cgmin/20210402/glibc/build/mathvec:/home/cgmin/20210402/glibc/build/support:/home/cgmin/20210402/glibc/build/crypt:/home/cgmin/20210402/glibc/build/nptl ${1+"$@"}
    ;;
  *)
    usage
    ;;
esac
