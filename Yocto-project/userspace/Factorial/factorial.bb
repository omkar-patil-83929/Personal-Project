SUMMARY = "Calculate Factorial"

LICENSE = "MIT"

LIC_FILES_CHCKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=1234567890"

SRC_URI = "file://factorial.c"

S = "${WORKDIR}/build"

do compile() {
   ${CC} ${CFLAGS} ${LDFLAGS} ${WORKDIR}/factorial.c -o ${S}/factorial
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/factorial ${D}${bindir}/
}
