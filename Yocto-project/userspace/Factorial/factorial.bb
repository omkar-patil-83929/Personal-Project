SUMMARY = "Calculate Factorial"

LICENSE = "MIT"

FILEEXTRAPATHS:prepend := "${THISDIR}/factorial:"

LIC_FILES_CHCKSUM = "file://COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"


SRC_URI = "file://factorial.c \
            file://COPYING.MIT"

S = "${WORKDIR}"

do compile() {

    mkdir -p {S}
   ${CC} ${CFLAGS} ${LDFLAGS} ${WORKDIR}/factorial.c -o ${S}/factorial
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/factorial ${D}${bindir}/
}
